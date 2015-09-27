#ifndef RTS_MAP_H_
#define RTS_MAP_H_

#include "rts/game_object.h"
#include "dioptre/ai/detour/navigation_mesh.h"

namespace rts {

const double cellSize = 1.0;

class Map : public rts::GameObject {
public:
  Map(dioptre::ai::detour::NavigationMesh *navigationMesh)
      : rts::GameObject("objects.map"), navigationMesh_(navigationMesh) {}

  void setNavigationMesh();
  void handleClick(glm::vec3 hitPoint);
  glm::vec3 findPath(glm::vec3 from, glm::vec3 to);

  static Map *spawn();

private:
  dioptre::ai::detour::NavigationMesh *navigationMesh_;
}; // Map

} // rts

#endif // RTS_MAP_H_
