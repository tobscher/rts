#include "dioptre/graphics/geometry.h"

namespace dioptre {
namespace graphics {

Geometry::Geometry() :
  isInitialized_(false),
  isDirty_(false) {
  logger_ = spdlog::get("dioptre");
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

void Geometry::addVertex(glm::vec3 vertex) {
  vertices_.push_back(vertex);
  isDirty_ = true;
}

void Geometry::addUV(glm::vec2 uv) {
  uvs_.push_back(uv);
  isDirty_ = true;
}

void Geometry::addNormal(glm::vec3 normal) {
  normals_.push_back(normal);
  isDirty_ = true;
}

void Geometry::clearVertices() {
  vertices_.clear();
  isDirty_ = true;
}

void Geometry::clearUVs() {
  uvs_.clear();
  isDirty_ = true;
}

void Geometry::clearNormals() {
  normals_.clear();
  isDirty_ = true;
}

bool Geometry::isInitialized() {
  return isInitialized_;
}

void Geometry::setIsInitialized(bool value) {
  isInitialized_ = value;
}

}
}
