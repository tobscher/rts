#ifndef DIOPTRE_AI_DETOUR_NAVIGATION_MESH_H_
#define DIOPTRE_AI_DETOUR_NAVIGATION_MESH_H_

#include "dioptre/ai/recast/navigation_mesh.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"

namespace dioptre {
namespace ai {
namespace detour {

class NavigationMesh {

  enum SamplePolyAreas {
    SAMPLE_POLYAREA_GROUND,
    SAMPLE_POLYAREA_WATER,
    SAMPLE_POLYAREA_ROAD,
    SAMPLE_POLYAREA_DOOR,
    SAMPLE_POLYAREA_GRASS,
    SAMPLE_POLYAREA_JUMP,
  };
  enum SamplePolyFlags {
    SAMPLE_POLYFLAGS_WALK = 0x01,     // Ability to walk (ground, grass, road)
    SAMPLE_POLYFLAGS_SWIM = 0x02,     // Ability to swim (water).
    SAMPLE_POLYFLAGS_DOOR = 0x04,     // Ability to move through doors.
    SAMPLE_POLYFLAGS_JUMP = 0x08,     // Ability to jump.
    SAMPLE_POLYFLAGS_DISABLED = 0x10, // Disabled polygon
    SAMPLE_POLYFLAGS_ALL = 0xffff     // All abilities.
  };

public:
  static const int MAX_POLYS = 256;

  NavigationMesh(dioptre::ai::recast::NavigationMesh *mesh);
  bool build();
  glm::vec3 find(glm::vec3 from, glm::vec3 to);

private:
  dioptre::ai::recast::NavigationMesh *mesh_;
  dtNavMesh *navMesh_;
  dtNavMeshQuery *navQuery_;

  dtStatus pathFindStatus_;
  bool sposSet_;
  bool eposSet_;
  dtPolyRef startRef_;
  dtPolyRef endRef_;
  float polyPickExt_[3];
  float spos_[3];
  float epos_[3];
  dtQueryFilter filter_;
  dtPolyRef polys_[MAX_POLYS];
  int npolys_;
  int nstraightPath_;
  float straightPath_[MAX_POLYS * 3];
  unsigned char straightPathFlags_[MAX_POLYS];
  dtPolyRef straightPathPolys_[MAX_POLYS];
  int straightPathOptions_;
}; // NavigationMesh

} // detour
} // ai
} // dioptre

#endif // DIOPTRE_AI_DETOUR_NAVIGATION_MESH_H_
