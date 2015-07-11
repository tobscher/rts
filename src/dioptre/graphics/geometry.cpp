#include "dioptre/graphics/geometry.h"

namespace dioptre {
namespace graphics {

Geometry::Geometry() :
  isInitialized_(false) {
  logger_ = log4cxx::Logger::getLogger("dioptre.geometry");
}

std::vector<glm::vec3> Geometry::getData() {
  return vertices_;
}

std::vector<glm::vec2> Geometry::getUVData() {
  return uvs_;
}

std::vector<glm::vec3> Geometry::getNormalData() {
  return normals_;
}

bool Geometry::isInitialized() {
  return isInitialized_;
}

void Geometry::setIsInitialized(bool value) {
  isInitialized_ = value;
}

}
}
