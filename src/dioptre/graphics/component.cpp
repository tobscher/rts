#include "dioptre/graphics/component.h"
#include "dioptre/locator.h"

#include <iostream>

namespace dioptre {
namespace graphics {

Component::Component(Mesh* mesh) :
  ComponentInterface("dioptre.graphics.component"),
  mesh_(mesh)
{
  mesh->setComponent(this);

  auto graphicsService = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto scene = graphicsService->getScene();
  scene->add(mesh);
}

Component::~Component() {
  delete mesh_;
}

void Component::update() {
}

} // graphics
} // dioptre
