#include "dioptre/graphics/component.h"
#include "dioptre/locator.h"

namespace dioptre {
namespace graphics {

Component::Component(Mesh* mesh) :
  ComponentInterface("dioptre.graphics.component"),
  mesh_(mesh),
  projector_(nullptr)
{
  mesh->setComponent(this);

  auto graphicsService = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto scene = graphicsService->getScene();
  scene->add(mesh);
}

Component::~Component() {
  delete mesh_;
}

Mesh* Component::getMesh() {
  return mesh_;
}

void Component::update() {
}

Projector* Component::getProjector() {
  return projector_;
}

void Component::setProjector(Projector* projector) {
  auto graphicsService = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  graphicsService->setProjector(projector);

  projector_ = projector;
}

} // graphics
} // dioptre
