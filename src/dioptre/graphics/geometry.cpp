#include "dioptre/graphics/geometry.h"

namespace dioptre {
namespace graphics {

std::vector<glm::vec3> Geometry::getData() {
  return vertices_;
}

bool Geometry::isInitialized() {
  return isInitialized_;
}

void Geometry::setIsInitialized(bool value) {
  isInitialized_ = value;
}

}
}
