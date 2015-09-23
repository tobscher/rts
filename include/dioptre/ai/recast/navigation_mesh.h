#ifndef DIOPTRE_AI_RECAST_NAVIGATION_MESH_H_
#define DIOPTRE_AI_RECAST_NAVIGATION_MESH_H_

#include "dioptre/ai/navigation_mesh.h"
#include "dioptre/graphics/box_geometry.h"
#include "Recast.h"

namespace dioptre {
namespace ai {
namespace recast {

class NavigationMesh : public dioptre::ai::NavigationMesh {
public:
  explicit NavigationMesh(dioptre::graphics::BoxGeometry *geometry);
  void build();
  rcPolyMesh *getPolyMesh() { return polyMesh_; }
  rcPolyMeshDetail *getPolyMeshDetail() { return polyMeshDetail_; }
  rcConfig getConfig() { return config_; }
  float getAgentHeight() { return agentHeight_; }
  float getAgentRadius() { return agentRadius_; }
  float getAgentMaxClimb() { return agentMaxClimb_; }
  rcContext *getContext() { return context_; }

private:
  dioptre::graphics::BoxGeometry *geometry_;

  float cellSize_;
  float cellHeight_;
  float agentHeight_;
  float agentMaxClimb_;
  float agentRadius_;
  float maxSlope_;
  float edgeMaxLen_;
  float edgeMaxError_;
  int regionMinSize_;
  int regionMergeSize_;
  int vertsPerPoly_;
  float detailSampleDistance_;
  float detailSampleMaxError_;

  unsigned char *triAreas_;

  rcContext *context_;
  rcConfig config_;
  rcHeightfield *solid_;
  rcCompactHeightfield *compact_;
  rcContourSet *contourSet_;
  rcPolyMesh *polyMesh_;
  rcPolyMeshDetail *polyMeshDetail_;

  void configure();
  bool rasterize();
  bool filter();
  bool partition();
  bool simplify();
  bool buildPolygons();
  bool createDetailMesh();
}; // NavigationMesh

} // recast
} // ai
} // dioptre

#endif // DIOPTRE_AI_RECAST_NAVIGATION_MESH_H_
