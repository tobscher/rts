#include "dioptre/graphics/mesh.h"

namespace dioptre {
namespace graphics {

Mesh::Mesh(Geometry* geometry, Material* material) :
  isInitialized_(false),
  geometry_(geometry),
  material_(material) {
}

bool Mesh::isInitialized() {
  return isInitialized_;
}

void Mesh::setIsInitialized(bool value) {
  isInitialized_ = value;
}

} // graphics
} // dioptre
