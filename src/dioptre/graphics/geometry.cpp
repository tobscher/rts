#include "dioptre/graphics/geometry.h"

namespace dioptre {
namespace graphics {

std::vector<glm::vec3> Geometry::getData() {
  return vertices_;
}

std::vector<glm::vec2> Geometry::getUVData() {
  return uvs_;
}

bool Geometry::isInitialized() {
  return isInitialized_;
}

void Geometry::setIsInitialized(bool value) {
  isInitialized_ = value;
}

}
}
