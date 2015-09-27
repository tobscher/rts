#include "dioptre/ai/detour/navigation_mesh.h"
#include "dioptre/graphics/debug.h"
#include "dioptre/locator.h"

#include "DetourNavMeshBuilder.h"
#include "DetourStatus.h"
#include "DetourCommon.h"

namespace dioptre {
namespace ai {
namespace detour {

NavigationMesh::NavigationMesh(dioptre::ai::recast::NavigationMesh *mesh)
    : mesh_(mesh), sposSet_(true), eposSet_(true), startRef_(0), endRef_(0) {
  navQuery_ = new dtNavMeshQuery();
  polyPickExt_[0] = 2;
  polyPickExt_[1] = 4;
  polyPickExt_[2] = 2;

  spos_[0] = 0.0;
  spos_[1] = 0.0;
  spos_[2] = 0.0;

  epos_[0] = 0.0;
  epos_[1] = 0.0;
  epos_[2] = 0.0;

  filter_.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
  filter_.setExcludeFlags(0);

  srand(static_cast<unsigned>(::time(0)));
}

bool NavigationMesh::build() {
  unsigned char *navData = 0;
  int navDataSize = 0;

  auto polyMesh = mesh_->getPolyMesh();

  // Update poly flags from areas.
  for (int i = 0; i < polyMesh->npolys; ++i) {
    if (polyMesh->areas[i] == RC_WALKABLE_AREA)
      polyMesh->areas[i] = SAMPLE_POLYAREA_GROUND;

    if (polyMesh->areas[i] == SAMPLE_POLYAREA_GROUND ||
        polyMesh->areas[i] == SAMPLE_POLYAREA_GRASS ||
        polyMesh->areas[i] == SAMPLE_POLYAREA_ROAD) {
      polyMesh->flags[i] = SAMPLE_POLYFLAGS_WALK;
    } else if (polyMesh->areas[i] == SAMPLE_POLYAREA_WATER) {
      polyMesh->flags[i] = SAMPLE_POLYFLAGS_SWIM;
    } else if (polyMesh->areas[i] == SAMPLE_POLYAREA_DOOR) {
      polyMesh->flags[i] = SAMPLE_POLYFLAGS_WALK | SAMPLE_POLYFLAGS_DOOR;
    }
  }

  auto polyMeshDetail = mesh_->getPolyMeshDetail();
  auto config = mesh_->getConfig();
  auto context = mesh_->getContext();

  dtNavMeshCreateParams params;
  memset(&params, 0, sizeof(params));
  params.verts = polyMesh->verts;
  params.vertCount = polyMesh->nverts;
  params.polys = polyMesh->polys;
  params.polyAreas = polyMesh->areas;
  params.polyFlags = polyMesh->flags;
  params.polyCount = polyMesh->npolys;
  params.nvp = polyMesh->nvp;
  params.detailMeshes = polyMeshDetail->meshes;
  params.detailVerts = polyMeshDetail->verts;
  params.detailVertsCount = polyMeshDetail->nverts;
  params.detailTris = polyMeshDetail->tris;
  params.detailTriCount = polyMeshDetail->ntris;
  /* params.offMeshConVerts = m_geom->getOffMeshConnectionVerts(); */
  /* params.offMeshConRad = m_geom->getOffMeshConnectionRads(); */
  /* params.offMeshConDir = m_geom->getOffMeshConnectionDirs(); */
  /* params.offMeshConAreas = m_geom->getOffMeshConnectionAreas(); */
  /* params.offMeshConFlags = m_geom->getOffMeshConnectionFlags(); */
  /* params.offMeshConUserID = m_geom->getOffMeshConnectionId(); */
  /* params.offMeshConCount = m_geom->getOffMeshConnectionCount(); */
  params.walkableHeight = mesh_->getAgentHeight();
  params.walkableRadius = mesh_->getAgentRadius();
  params.walkableClimb = mesh_->getAgentMaxClimb();
  rcVcopy(params.bmin, polyMesh->bmin);
  rcVcopy(params.bmax, polyMesh->bmax);
  params.cs = config.cs;
  params.ch = config.ch;
  params.buildBvTree = true;

  if (!dtCreateNavMeshData(&params, &navData, &navDataSize)) {
    context->log(RC_LOG_ERROR, "Could not build Detour navmesh.");
    return false;
  }

  navMesh_ = dtAllocNavMesh();
  if (!navMesh_) {
    dtFree(navData);
    context->log(RC_LOG_ERROR, "Could not create Detour navmesh");
    return false;
  }

  dtStatus status;

  status = navMesh_->init(navData, navDataSize, DT_TILE_FREE_DATA);
  if (dtStatusFailed(status)) {
    dtFree(navData);
    context->log(RC_LOG_ERROR, "Could not init Detour navmesh");
    return false;
  }

  status = navQuery_->init(navMesh_, 2048);
  if (dtStatusFailed(status)) {
    context->log(RC_LOG_ERROR, "Could not init Detour navmesh query");
    return false;
  }

  context->stopTimer(RC_TIMER_TOTAL);

  // Show performance stats.
  /* duLogBuildTimes(*context, context->getAccumulatedTime(RC_TIMER_TOTAL)); */
  context->log(RC_LOG_PROGRESS, ">> Polymesh: %d vertices  %d polygons",
               polyMesh->nverts, polyMesh->npolys);

  std::cout << "Nav Mesh Query" << std::endl;

  return true;
}

static float frand() {
  //	return ((float)(rand() & 0xffff)/(float)0xffff);
  return (float)rand() / (float)RAND_MAX;
}

glm::vec3 NavigationMesh::find(glm::vec3 from, glm::vec3 to) {
  /* if (sposSet_) { */
  /*   std::cout << "Start set:" << std::endl; */
  spos_[0] = from.x;
  spos_[1] = from.y;
  spos_[2] = from.z;
  navQuery_->findNearestPoly(spos_, polyPickExt_, &filter_, &startRef_, 0);
  /* } else { */
  /*   startRef_ = 0; */
  /* } */

  /* navQuery_->findRandomPoint(&filter_, frand, &startRef_, spos_); */

  /* if (eposSet_) { */
  /*   std::cout << "End set:" << std::endl; */
  epos_[0] = to.x;
  epos_[1] = to.y;
  epos_[2] = to.z;
  navQuery_->findNearestPoly(epos_, polyPickExt_, &filter_, &endRef_, 0);
  /* } else { */
  /*   endRef_ = 0; */
  /* } */

  /* navQuery_->findRandomPoint(&filter_, frand, &endRef_, epos_); */

  /* std::cout << "spos:" << spos_[0] << "x" << spos_[1] << "x" << spos_[2] */
  /*           << std::endl; */
  /* std::cout << "epos:" << epos_[0] << "x" << epos_[1] << "x" << epos_[2] */
  /*           << std::endl; */

  pathFindStatus_ = DT_FAILURE;

  /* if (m_toolMode == TOOLMODE_PATHFIND_FOLLOW) { */
  /*   m_pathIterNum = 0; */
  /*   if (m_sposSet && m_eposSet && m_startRef && m_endRef) { */
  /* #ifdef DUMP_REQS */
  /*     printf("pi  %f %f %f  %f %f %f  0x%x 0x%x\n", m_spos[0], m_spos[1], */
  /*            m_spos[2], m_epos[0], m_epos[1], m_epos[2], */
  /*            m_filter.getIncludeFlags(), m_filter.getExcludeFlags()); */
  /* #endif */

  /*     m_navQuery->findPath(m_startRef, m_endRef, m_spos, m_epos, &m_filter,
   */
  /*                          m_polys, &m_npolys, MAX_POLYS); */

  /*     m_nsmoothPath = 0; */

  /*     if (m_npolys) { */
  /*       // Iterate over the path to find smooth path on the detail mesh
   * surface. */
  /*       dtPolyRef polys[MAX_POLYS]; */
  /*       memcpy(polys, m_polys, sizeof(dtPolyRef) * m_npolys); */
  /*       int npolys = m_npolys; */

  /*       float iterPos[3], targetPos[3]; */
  /*       m_navQuery->closestPointOnPoly(m_startRef, m_spos, iterPos, 0); */
  /*       m_navQuery->closestPointOnPoly(polys[npolys - 1], m_epos, targetPos,
   * 0); */

  /*       static const float STEP_SIZE = 0.5f; */
  /*       static const float SLOP = 0.01f; */

  /*       m_nsmoothPath = 0; */

  /*       dtVcopy(&m_smoothPath[m_nsmoothPath * 3], iterPos); */
  /*       m_nsmoothPath++; */

  /*       // Move towards target a small advancement at a time until target */
  /*       // reached or */
  /*       // when ran out of memory to store the path. */
  /*       while (npolys && m_nsmoothPath < MAX_SMOOTH) { */
  /*         // Find location to steer towards. */
  /*         float steerPos[3]; */
  /*         unsigned char steerPosFlag; */
  /*         dtPolyRef steerPosRef; */

  /*         if (!getSteerTarget(m_navQuery, iterPos, targetPos, SLOP, polys, */
  /*                             npolys, steerPos, steerPosFlag, steerPosRef))
   */
  /*           break; */

  /*         bool endOfPath = (steerPosFlag & DT_STRAIGHTPATH_END) ? true :
   * false; */
  /*         bool offMeshConnection = */
  /*             (steerPosFlag & DT_STRAIGHTPATH_OFFMESH_CONNECTION) ? true */
  /*                                                                 : false; */

  /*         // Find movement delta. */
  /*         float delta[3], len; */
  /*         dtVsub(delta, steerPos, iterPos); */
  /*         len = dtMathSqrtf(dtVdot(delta, delta)); */
  /*         // If the steer target is end of path or off-mesh link, do not move
   */
  /*         // past the location. */
  /*         if ((endOfPath || offMeshConnection) && len < STEP_SIZE) */
  /*           len = 1; */
  /*         else */
  /*           len = STEP_SIZE / len; */
  /*         float moveTgt[3]; */
  /*         dtVmad(moveTgt, iterPos, delta, len); */

  /*         // Move */
  /*         float result[3]; */
  /*         dtPolyRef visited[16]; */
  /*         int nvisited = 0; */
  /*         m_navQuery->moveAlongSurface(polys[0], iterPos, moveTgt, &m_filter,
   */
  /*                                      result, visited, &nvisited, 16); */

  /*         npolys = fixupCorridor(polys, npolys, MAX_POLYS, visited,
   * nvisited); */
  /*         npolys = fixupShortcuts(polys, npolys, m_navQuery); */

  /*         float h = 0; */
  /*         m_navQuery->getPolyHeight(polys[0], result, &h); */
  /*         result[1] = h; */
  /*         dtVcopy(iterPos, result); */

  /*         // Handle end of path and off-mesh links when close enough. */
  /*         if (endOfPath && inRange(iterPos, steerPos, SLOP, 1.0f)) { */
  /*           // Reached end of path. */
  /*           dtVcopy(iterPos, targetPos); */
  /*           if (m_nsmoothPath < MAX_SMOOTH) { */
  /*             dtVcopy(&m_smoothPath[m_nsmoothPath * 3], iterPos); */
  /*             m_nsmoothPath++; */
  /*           } */
  /*           break; */
  /*         } else if (offMeshConnection && */
  /*                    inRange(iterPos, steerPos, SLOP, 1.0f)) { */
  /*           // Reached off-mesh connection. */
  /*           float startPos[3], endPos[3]; */

  /*           // Advance the path up to and over the off-mesh connection. */
  /*           dtPolyRef prevRef = 0, polyRef = polys[0]; */
  /*           int npos = 0; */
  /*           while (npos < npolys && polyRef != steerPosRef) { */
  /*             prevRef = polyRef; */
  /*             polyRef = polys[npos]; */
  /*             npos++; */
  /*           } */
  /*           for (int i = npos; i < npolys; ++i) */
  /*             polys[i - npos] = polys[i]; */
  /*           npolys -= npos; */

  /*           // Handle the connection. */
  /*           dtStatus status = m_navMesh->getOffMeshConnectionPolyEndPoints(
   */
  /*               prevRef, polyRef, startPos, endPos); */
  /*           if (dtStatusSucceed(status)) { */
  /*             if (m_nsmoothPath < MAX_SMOOTH) { */
  /*               dtVcopy(&m_smoothPath[m_nsmoothPath * 3], startPos); */
  /*               m_nsmoothPath++; */
  /*               // Hack to make the dotted path not visible during off-mesh
   */
  /*               // connection. */
  /*               if (m_nsmoothPath & 1) { */
  /*                 dtVcopy(&m_smoothPath[m_nsmoothPath * 3], startPos); */
  /*                 m_nsmoothPath++; */
  /*               } */
  /*             } */
  /*             // Move position at the other side of the off-mesh link. */
  /*             dtVcopy(iterPos, endPos); */
  /*             float eh = 0.0f; */
  /*             m_navQuery->getPolyHeight(polys[0], iterPos, &eh); */
  /*             iterPos[1] = eh; */
  /*           } */
  /*         } */

  /*         // Store results. */
  /*         if (m_nsmoothPath < MAX_SMOOTH) { */
  /*           dtVcopy(&m_smoothPath[m_nsmoothPath * 3], iterPos); */
  /*           m_nsmoothPath++; */
  /*         } */
  /*       } */
  /*     } */

  /*   } else { */
  /*     m_npolys = 0; */
  /*     m_nsmoothPath = 0; */
  /*   } */
  /* } else if (m_toolMode == TOOLMODE_PATHFIND_STRAIGHT) { */
  if (sposSet_ && eposSet_ && startRef_ && endRef_) {
    /* #ifdef DUMP_REQS */
    printf("ps  %f %f %f  %f %f %f  0x%x 0x%x\n", spos_[0], spos_[1], spos_[2],
           epos_[0], epos_[1], epos_[2], filter_.getIncludeFlags(),
           filter_.getExcludeFlags());
    /* #endif */
    navQuery_->findPath(startRef_, endRef_, spos_, epos_, &filter_, polys_,
                        &npolys_, MAX_POLYS);
    nstraightPath_ = 0;

    if (npolys_) {
      // In case of partial path, make sure the end point is clamped to the
      // last polygon.
      float epos[3];
      dtVcopy(epos, epos_);
      if (polys_[npolys_ - 1] != endRef_)
        navQuery_->closestPointOnPoly(polys_[npolys_ - 1], epos_, epos, 0);

      navQuery_->findStraightPath(
          spos_, epos, polys_, npolys_, straightPath_, straightPathFlags_,
          straightPathPolys_, &nstraightPath_, MAX_POLYS, straightPathOptions_);

      for (int i = 0; i < nstraightPath_ - 1; ++i) {
        /* std::cout << "From:" << straightPath_[i * 3] << "x" */
        /*           << straightPath_[i * 3 + 1] << "x" << straightPath_[i * 3 +
         * 2] */
        /*           << std::endl; */

        std::cout << "To:" << straightPath_[(i + 1) * 3] << "x"
                  << straightPath_[(i + 1) * 3 + 1] << "x"
                  << straightPath_[(i + 1) * 3 + 2] << std::endl;

        auto graphics =
            dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(
                dioptre::Module::M_GRAPHICS);
        auto debug = (dioptre::graphics::Debug *)graphics->getLayer(2);
        debug->addLine(glm::vec3(straightPath_[i * 3], straightPath_[i * 3 + 1],
                                 straightPath_[i * 3 + 2]),
                       glm::vec3(straightPath_[(i + 1) * 3],
                                 straightPath_[(i + 1) * 3 + 1],
                                 straightPath_[(i + 1) * 3 + 2]));
      }

      return glm::vec3(straightPath_[1 * 3], straightPath_[1 * 3 + 1],
                       straightPath_[1 * 3 + 2]);
    }
  } else {
    npolys_ = 0;
    nstraightPath_ = 0;
  }
  /* } else if (m_toolMode == TOOLMODE_PATHFIND_SLICED) { */
  /*   if (m_sposSet && m_eposSet && m_startRef && m_endRef) { */
  /* #ifdef DUMP_REQS */
  /*     printf("ps  %f %f %f  %f %f %f  0x%x 0x%x\n", m_spos[0], m_spos[1], */
  /*            m_spos[2], m_epos[0], m_epos[1], m_epos[2], */
  /*            m_filter.getIncludeFlags(), m_filter.getExcludeFlags()); */
  /* #endif */
  /*     m_npolys = 0; */
  /*     m_nstraightPath = 0; */

  /*     m_pathFindStatus = */
  /*         m_navQuery->initSlicedFindPath(m_startRef, m_endRef, m_spos,
   * m_epos, */
  /*                                        &m_filter, DT_FINDPATH_ANY_ANGLE);
   */
  /*   } else { */
  /*     m_npolys = 0; */
  /*     m_nstraightPath = 0; */
  /*   } */
  /* } else if (m_toolMode == TOOLMODE_RAYCAST) { */
  /*   m_nstraightPath = 0; */
  /*   if (m_sposSet && m_eposSet && m_startRef) { */
  /* #ifdef DUMP_REQS */
  /*     printf("rc  %f %f %f  %f %f %f  0x%x 0x%x\n", m_spos[0], m_spos[1], */
  /*            m_spos[2], m_epos[0], m_epos[1], m_epos[2], */
  /*            m_filter.getIncludeFlags(), m_filter.getExcludeFlags()); */
  /* #endif */
  /*     float t = 0; */
  /*     m_npolys = 0; */
  /*     m_nstraightPath = 2; */
  /*     m_straightPath[0] = m_spos[0]; */
  /*     m_straightPath[1] = m_spos[1]; */
  /*     m_straightPath[2] = m_spos[2]; */
  /*     m_navQuery->raycast(m_startRef, m_spos, m_epos, &m_filter, &t, */
  /*                         m_hitNormal, m_polys, &m_npolys, MAX_POLYS); */
  /*     if (t > 1) { */
  /*       // No hit */
  /*       dtVcopy(m_hitPos, m_epos); */
  /*       m_hitResult = false; */
  /*     } else { */
  /*       // Hit */
  /*       dtVlerp(m_hitPos, m_spos, m_epos, t); */
  /*       m_hitResult = true; */
  /*     } */
  /*     // Adjust height. */
  /*     if (m_npolys > 0) { */
  /*       float h = 0; */
  /*       m_navQuery->getPolyHeight(m_polys[m_npolys - 1], m_hitPos, &h); */
  /*       m_hitPos[1] = h; */
  /*     } */
  /*     dtVcopy(&m_straightPath[3], m_hitPos); */
  /*   } */
  /* } else if (m_toolMode == TOOLMODE_DISTANCE_TO_WALL) { */
  /*   m_distanceToWall = 0; */
  /*   if (m_sposSet && m_startRef) { */
  /* #ifdef DUMP_REQS */
  /*     printf("dw  %f %f %f  %f  0x%x 0x%x\n", m_spos[0], m_spos[1],
   * m_spos[2], */
  /*            100.0f, m_filter.getIncludeFlags(), m_filter.getExcludeFlags());
   */
  /* #endif */
  /*     m_distanceToWall = 0.0f; */
  /*     m_navQuery->findDistanceToWall(m_startRef, m_spos, 100.0f, &m_filter,
   */
  /*                                    &m_distanceToWall, m_hitPos,
   * m_hitNormal); */
  /*   } */
  /* } else if (m_toolMode == TOOLMODE_FIND_POLYS_IN_CIRCLE) { */
  /*   if (m_sposSet && m_startRef && m_eposSet) { */
  /*     const float dx = m_epos[0] - m_spos[0]; */
  /*     const float dz = m_epos[2] - m_spos[2]; */
  /*     float dist = sqrtf(dx * dx + dz * dz); */
  /* #ifdef DUMP_REQS */
  /*     printf("fpc  %f %f %f  %f  0x%x 0x%x\n", m_spos[0], m_spos[1],
   * m_spos[2], */
  /*            dist, m_filter.getIncludeFlags(), m_filter.getExcludeFlags());
   */
  /* #endif */
  /*     m_navQuery->findPolysAroundCircle(m_startRef, m_spos, dist, &m_filter,
   */
  /*                                       m_polys, m_parent, 0, &m_npolys, */
  /*                                       MAX_POLYS); */
  /*   } */
  /* } else if (m_toolMode == TOOLMODE_FIND_POLYS_IN_SHAPE) { */
  /*   if (m_sposSet && m_startRef && m_eposSet) { */
  /*     const float nx = (m_epos[2] - m_spos[2]) * 0.25f; */
  /*     const float nz = -(m_epos[0] - m_spos[0]) * 0.25f; */
  /*     const float agentHeight = m_sample ? m_sample->getAgentHeight() : 0; */

  /*     m_queryPoly[0] = m_spos[0] + nx * 1.2f; */
  /*     m_queryPoly[1] = m_spos[1] + agentHeight / 2; */
  /*     m_queryPoly[2] = m_spos[2] + nz * 1.2f; */

  /*     m_queryPoly[3] = m_spos[0] - nx * 1.3f; */
  /*     m_queryPoly[4] = m_spos[1] + agentHeight / 2; */
  /*     m_queryPoly[5] = m_spos[2] - nz * 1.3f; */

  /*     m_queryPoly[6] = m_epos[0] - nx * 0.8f; */
  /*     m_queryPoly[7] = m_epos[1] + agentHeight / 2; */
  /*     m_queryPoly[8] = m_epos[2] - nz * 0.8f; */

  /*     m_queryPoly[9] = m_epos[0] + nx; */
  /*     m_queryPoly[10] = m_epos[1] + agentHeight / 2; */
  /*     m_queryPoly[11] = m_epos[2] + nz; */

  /* #ifdef DUMP_REQS */
  /*     printf("fpp  %f %f %f  %f %f %f  %f %f %f  %f %f %f  0x%x 0x%x\n", */
  /*            m_queryPoly[0], m_queryPoly[1], m_queryPoly[2], m_queryPoly[3],
   */
  /*            m_queryPoly[4], m_queryPoly[5], m_queryPoly[6], m_queryPoly[7],
   */
  /*            m_queryPoly[8], m_queryPoly[9], m_queryPoly[10],
   * m_queryPoly[11], */
  /*            m_filter.getIncludeFlags(), m_filter.getExcludeFlags()); */
  /* #endif */
  /*     m_navQuery->findPolysAroundShape(m_startRef, m_queryPoly, 4, &m_filter,
   */
  /*                                      m_polys, m_parent, 0, &m_npolys, */
  /*                                      MAX_POLYS); */
  /*   } */
  /* } else if (m_toolMode == TOOLMODE_FIND_LOCAL_NEIGHBOURHOOD) { */
  /*   if (m_sposSet && m_startRef) { */
  /* #ifdef DUMP_REQS */
  /*     printf("fln  %f %f %f  %f  0x%x 0x%x\n", m_spos[0], m_spos[1],
   * m_spos[2], */
  /*            m_neighbourhoodRadius, m_filter.getIncludeFlags(), */
  /*            m_filter.getExcludeFlags()); */
  /* #endif */
  /*     m_navQuery->findLocalNeighbourhood( */
  /*         m_startRef, m_spos, m_neighbourhoodRadius, &m_filter, m_polys, */
  /*         m_parent, &m_npolys, MAX_POLYS); */
  /*   } */
  /* } */

  return glm::vec3(0, 1, 0);
}

} // recast
} // ai
} // dioptre
