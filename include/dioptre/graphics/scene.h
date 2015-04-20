#ifndef DIOPTRE_GRAPHICS_SCENE_H_
#define DIOPTRE_GRAPHICS_SCENE_H_

#include <vector>
#include "mesh.h"

namespace dioptre {
namespace graphics {

class Scene {
public:
  void add(Mesh* mesh);

  std::vector<Mesh*>::iterator begin();
  std::vector<Mesh*>::iterator end();

private:
  std::vector<Mesh*> meshes_;
}; // Scene

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_SCENE_H_
