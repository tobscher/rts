#include "dioptre/graphics/scene.h"
#include "dioptre/graphics/mesh.h"

#include <vector>

namespace dioptre {
namespace graphics {

std::vector<Mesh*>::iterator Scene::begin() {
  return meshes_.begin();
}

std::vector<Mesh*>::iterator Scene::end() {
  return meshes_.end();
}

void Scene::add(Mesh* mesh) {
  meshes_.push_back(mesh);
}

}
}
