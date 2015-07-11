#include "dioptre/graphics/component.h"
#include "dioptre/locator.h"

namespace dioptre {
namespace graphics {

Component::Component(Mesh* mesh) :
  ComponentInterface("dioptre.graphics.component"),
  mesh_(mesh)
{
  auto graphicsService = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto scene = graphicsService->getScene();
  scene->add(mesh);
}

void Component::update() {
}

// Translation
void Component::setPosition(glm::float32 x, glm::float32 y, glm::float32 z) {
  mesh_->getTransform()->setPosition(x,y,z);
}

void Component::translateX(glm::float32 x) {
  mesh_->getTransform()->translateX(x);
}

void Component::translateY(glm::float32 y) {
  mesh_->getTransform()->translateY(y);
}

void Component::translateZ(glm::float32 z) {
  mesh_->getTransform()->translateZ(z);
}

void Component::translate(glm::vec3 v) {
  mesh_->getTransform()->translate(v);
}

// Scale
void Component::setScale(glm::float32 x, glm::float32 y, glm::float32 z) {
  mesh_->getTransform()->setScale(x, y, z);
}

// Rotation
void Component::rotateX(glm::float32 x) {
  mesh_->getTransform()->rotateX(x);
}

void Component::rotateY(glm::float32 y) {
  mesh_->getTransform()->rotateY(y);
}

void Component::rotateZ(glm::float32 z) {
  mesh_->getTransform()->rotateZ(z);
}

} // graphics
} // dioptre
