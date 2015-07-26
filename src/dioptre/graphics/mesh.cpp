#include "dioptre/graphics/mesh.h"

namespace dioptre {
namespace graphics {

Mesh::Mesh(Geometry* geometry, Material* material) :
  isInitialized_(false),
  geometry_(geometry),
  material_(material),
  component_(nullptr) {
}

bool Mesh::isInitialized() {
  return isInitialized_;
}

void Mesh::setIsInitialized(bool value) {
  isInitialized_ = value;
}

Geometry* Mesh::getGeometry() {
  return geometry_;
}

Material* Mesh::getMaterial() {
  return material_;
}

ComponentInterface* Mesh::getComponent() {
  return component_;
}

void Mesh::setComponent(ComponentInterface* component) {
  component_ = component;
}

} // graphics
} // dioptre
