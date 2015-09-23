#include "dioptre/ai/recast/navigation_mesh.h"
#include <cstring>
#include <cmath>

namespace dioptre {
namespace ai {
namespace recast {

NavigationMesh::NavigationMesh(dioptre::graphics::BoxGeometry *geometry)
    : geometry_(geometry), cellSize_(1.0), cellHeight_(0.2), agentHeight_(2.0),
      agentMaxClimb_(0.9), agentRadius_(0.6), maxSlope_(45.0), edgeMaxLen_(12),
      edgeMaxError_(1.3), regionMinSize_(8), regionMergeSize_(20),
      vertsPerPoly_(6), detailSampleDistance_(6), detailSampleMaxError_(1) {

  context_ = new rcContext();
}

void NavigationMesh::configure() {
  memset(&config_, 0, sizeof(config_));
  config_.cs = cellSize_;   // cell size
  config_.ch = cellHeight_; // cell height
  config_.walkableSlopeAngle = maxSlope_;
  config_.walkableHeight = (int)ceilf(agentHeight_ / config_.ch);
  config_.walkableClimb = (int)floorf(agentMaxClimb_ / config_.ch);
  config_.walkableRadius = (int)ceilf(agentRadius_ / config_.cs);
  config_.maxEdgeLen = (int)(edgeMaxLen_ / cellSize_);
  config_.maxSimplificationError = edgeMaxError_;
  config_.minRegionArea = (int)rcSqr(regionMinSize_); // Note: area = size*size
  config_.mergeRegionArea =
      (int)rcSqr(regionMergeSize_); // Note: area = size*size
  config_.maxVertsPerPoly = (int)vertsPerPoly_;
  config_.detailSampleDist =
      detailSampleDistance_ < 0.9f ? 0 : detailSampleDistance_ * cellSize_;
  config_.detailSampleMaxError = cellHeight_ * detailSampleMaxError_;

  auto bb = geometry_->getBoundingBox();
  auto min = bb->getMin();
  auto max = bb->getMax();
  float bmin[3] = {min.x, min.y, min.z};
  float bmax[3] = {max.x, max.y, max.z};

  rcVcopy(config_.bmin, bmin);
  rcVcopy(config_.bmax, bmax);

  rcCalcGridSize(config_.bmin, config_.bmax, config_.cs, &config_.width,
                 &config_.height);

  auto nverts = geometry_->getData().size();
  auto ntris = geometry_->getFaceData().size();

  context_->log(RC_LOG_PROGRESS, "Building navigation:");
  context_->log(RC_LOG_PROGRESS, " - %d x %d cells", config_.width,
                config_.height);
  context_->log(RC_LOG_PROGRESS, " - %.1fK verts, %.1fK tris", nverts / 1000.0f,
                ntris / 1000.0f);

  std::cout << "Filtered" << std::endl;
}

bool NavigationMesh::rasterize() {
  // Allocate voxel heightfield where we rasterize our input data to.
  solid_ = rcAllocHeightfield();
  if (!solid_) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'solid'.");
    return false;
  }
  if (!rcCreateHeightfield(context_, *solid_, config_.width, config_.height,
                           config_.bmin, config_.bmax, config_.cs,
                           config_.ch)) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Could not create solid heightfield.");
    return false;
  }

  auto bufferData = geometry_->getData();
  auto bufferFaceData = geometry_->getFaceData();
  auto ntris = bufferFaceData.size();
  auto nverts = bufferData.size();
  std::vector<float> verts;
  std::vector<int> tris;

  for (auto it = bufferData.begin(); it != bufferData.end(); it++) {
    verts.push_back(it->x);
    verts.push_back(it->y);
    verts.push_back(it->z);
  }

  for (auto it = bufferFaceData.begin(); it != bufferFaceData.end(); it++) {
    tris.push_back(it->x);
    tris.push_back(it->y);
    tris.push_back(it->z);
  }

  // Allocate array that can hold triangle area types.
  // If you have multiple meshes you need to process, allocate
  // and array which can hold the max number of triangles you need to process.
  triAreas_ = new unsigned char[ntris];
  if (!triAreas_) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Out of memory 'triAreas_' (%d).", ntris);
    return false;
  }

  // Find triangles which are walkable based on their slope and rasterize them.
  // If your input data is multiple meshes, you can transform them here,
  // calculate
  // the are type for each of the meshes and rasterize them.
  memset(triAreas_, 0, ntris * sizeof(unsigned char));

  rcMarkWalkableTriangles(context_, config_.walkableSlopeAngle, &verts[0],
                          nverts, &tris[0], ntris, triAreas_);
  rcRasterizeTriangles(context_, &verts[0], nverts, &tris[0], triAreas_, ntris,
                       *solid_, config_.walkableClimb);

  /* if (!m_keepInterResults) { */
  delete[] triAreas_;
  triAreas_ = nullptr;
  /* } */

  std::cout << "Rasterized" << std::endl;

  return true;
}

bool NavigationMesh::filter() {
  // Once all geoemtry is rasterized, we do initial pass of filtering to
  // remove unwanted overhangs caused by the conservative rasterization
  // as well as filter spans where the character cannot possibly stand.
  rcFilterLowHangingWalkableObstacles(context_, config_.walkableClimb, *solid_);
  rcFilterLedgeSpans(context_, config_.walkableHeight, config_.walkableClimb,
                     *solid_);
  rcFilterWalkableLowHeightSpans(context_, config_.walkableHeight, *solid_);

  std::cout << "Filtered" << std::endl;

  return true;
}

bool NavigationMesh::partition() {
  // Compact the heightfield so that it is faster to handle from now on.
  // This will result more cache coherent data as well as the neighbours
  // between walkable cells will be calculated.
  compact_ = rcAllocCompactHeightfield();
  if (!compact_) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'chf'.");
    return false;
  }
  if (!rcBuildCompactHeightfield(context_, config_.walkableHeight,
                                 config_.walkableClimb, *solid_, *compact_)) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Could not build compact data.");
    return false;
  }

  /* if (!m_keepInterResults) { */
  /* rcFreeHeightField(solid_); */
  /* solid_ = 0; */
  /* } */

  // Erode the walkable area by agent radius.
  if (!rcErodeWalkableArea(context_, config_.walkableRadius, *compact_)) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Could not erode.");
    return false;
  }

  // (Optional) Mark areas.
  /* const ConvexVolume *vols = m_geom->getConvexVolumes(); */
  /* for (int i = 0; i < m_geom->getConvexVolumeCount(); ++i) */
  /*   rcMarkConvexPolyArea(context_, vols[i].verts, vols[i].nverts,
   * vols[i].hmin, */
  /*                        vols[i].hmax, (unsigned char)vols[i].area,
   * *compact_); */

  // Partition the heightfield so that we can use simple algorithm later to
  // triangulate the walkable areas.
  // There are 3 martitioning methods, each with some pros and cons:
  // 1) Watershed partitioning
  //   - the classic Recast partitioning
  //   - creates the nicest tessellation
  //   - usually slowest
  //   - partitions the heightfield into nice regions without holes or overlaps
  //   - the are some corner cases where this method creates produces holes and
  //   overlaps
  //      - holes may appear when a small obstacles is close to large open area
  //      (triangulation can handle this)
  //      - overlaps may occur if you have narrow spiral corridors (i.e stairs),
  //      this make triangulation to fail
  //   * generally the best choice if you precompute the nacmesh, use this if
  //   you have large open areas
  // 2) Monotone partioning
  //   - fastest
  //   - partitions the heightfield into regions without holes and overlaps
  //   (guaranteed)
  //   - creates long thin polygons, which sometimes causes paths with detours
  //   * use this if you want fast navmesh generation
  // 3) Layer partitoining
  //   - quite fast
  //   - partitions the heighfield into non-overlapping regions
  //   - relies on the triangulation code to cope with holes (thus slower than
  //   monotone partitioning)
  //   - produces better triangles than monotone partitioning
  //   - does not have the corner cases of watershed partitioning
  //   - can be slow and create a bit ugly tessellation (still better than
  //   monotone)
  //     if you have large open areas with small obstacles (not a problem if you
  //     use tiles)
  //   * good choice to use for tiled navmesh with medium and small sized tiles

  /* if (m_partitionType == SAMPLE_PARTITION_WATERSHED) { */
  // Prepare for region partitioning, by calculating distance field along the
  // walkable surface.
  if (!rcBuildDistanceField(context_, *compact_)) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Could not build distance field.");
    return false;
  }

  // Partition the walkable surface into simple regions without holes.
  if (!rcBuildRegions(context_, *compact_, 0, config_.minRegionArea,
                      config_.mergeRegionArea)) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Could not build watershed regions.");
    return false;
  }
  /* } else if (m_partitionType == SAMPLE_PARTITION_MONOTONE) { */
  /*   // Partition the walkable surface into simple regions without holes. */
  /*   // Monotone partitioning does not need distancefield. */
  /*   if (!rcBuildRegionsMonotone(context_, *compact_, 0,
   * config_.minRegionArea, */
  /*                               config_.mergeRegionArea)) { */
  /*     context_->log(RC_LOG_ERROR, */
  /*                   "buildNavigation: Could not build monotone regions."); */
  /*     return false; */
  /*   } */
  /* } else // SAMPLE_PARTITION_LAYERS */
  /* { */
  /*   // Partition the walkable surface into simple regions without holes. */
  /*   if (!rcBuildLayerRegions(context_, *compact_, 0, config_.minRegionArea))
   * { */
  /*     context_->log(RC_LOG_ERROR, */
  /*                   "buildNavigation: Could not build layer regions."); */
  /*     return false; */
  /*   } */
  /* } */

  std::cout << "Partitioned" << std::endl;

  return true;
}

bool NavigationMesh::simplify() {
  // Create contours.
  contourSet_ = rcAllocContourSet();
  if (!contourSet_) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'cset'.");
    return false;
  }

  if (!rcBuildContours(context_, *compact_, config_.maxSimplificationError,
                       config_.maxEdgeLen, *contourSet_)) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Could not create contours.");
    return false;
  }

  std::cout << "Simplified" << std::endl;

  return true;
}

bool NavigationMesh::buildPolygons() {
  // Build polygon navmesh from the contours.
  polyMesh_ = rcAllocPolyMesh();
  if (!polyMesh_) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'pmesh'.");
    return false;
  }
  if (!rcBuildPolyMesh(context_, *contourSet_, config_.maxVertsPerPoly,
                       *polyMesh_)) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Could not triangulate contours.");
    return false;
  }

  std::cout << "Built Polygon Mesh" << std::endl;

  return true;
}

bool NavigationMesh::createDetailMesh() {
  polyMeshDetail_ = rcAllocPolyMeshDetail();
  if (!polyMeshDetail_) {
    context_->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'pmdtl'.");
    return false;
  }

  if (!rcBuildPolyMeshDetail(context_, *polyMesh_, *compact_,
                             config_.detailSampleDist,
                             config_.detailSampleMaxError, *polyMeshDetail_)) {
    context_->log(RC_LOG_ERROR,
                  "buildNavigation: Could not build detail mesh.");
    return false;
  }

  /* if (!m_keepInterResults) { */
  rcFreeCompactHeightfield(compact_);
  compact_ = nullptr;
  rcFreeContourSet(contourSet_);
  contourSet_ = nullptr;
  /* } */

  std::cout << "Built Polygon Mesh Detail" << std::endl;

  return true;
}

void NavigationMesh::build() {
  configure();
  rasterize();
  filter();
  partition();
  simplify();
  buildPolygons();
  createDetailMesh();

  rcHeightfield hf = *solid_;
  std::cout << "Bmin: " << hf.bmin[0] << "x" << hf.bmin[1] << "x" << hf.bmin[2]
            << std::endl;
  std::cout << "Bmax: " << hf.bmax[0] << "x" << hf.bmax[1] << "x" << hf.bmax[2]
            << std::endl;
  std::cout << "cs: " << hf.cs << std::endl;
  std::cout << "ch: " << hf.ch << std::endl;

  const float *orig = hf.bmin;
  const float cs = hf.cs;
  const float ch = hf.ch;
  const int w = hf.width;
  const int h = hf.height;

  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      /* // Deriving the minimum corner of the grid location. */
      float fx = orig[0] + x * cs;
      float fz = orig[2] + y * cs;

      // The base span in the column. (May be null.)
      const rcSpan *s = hf.spans[x + y * w];
      while (s) {
        // Detriving the minium and maximum world position of the span.
        float fymin = orig[1] + s->smin * ch;
        float fymax = orig[1] + s->smax * ch;

        /* std::cout << "X:" << fx << " - " */
        /*           << "Z:" << fz << " - " */
        /*           << "Min:" << fymin << " - " */
        /*           << "Max:" << fymax << std::endl; */

        // Do other things with the span before moving up the column.
        s = s->next;
      }
      /* float fx = orig[0] + x * cs; */
      /* float fz = orig[2] + y * cs; */
      /* const rcSpan *s = hf.spans[x + y * w]; */
      /* while (s) { */
      /*   printf("%4.2f %4.2f %4.2f %4.2f %4.2f %4.2f\n", fx, */
      /*          orig[1] + s->smin * ch, fz, fx + cs, orig[1] + s->smax * ch,
       */
      /*          fz + cs); */

      /*   s = s->next; */
      /* } */
    }
  }
}

} // recast
} // ai
} // dioptre
