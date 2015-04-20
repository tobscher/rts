#include "dioptre/graphics/component.h"
#include "dioptre/locator.h"

namespace dioptre {
namespace graphics {

Component::Component(Mesh* mesh) :
  mesh_(mesh) {
  auto graphicsService = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto scene = graphicsService->getScene();
  scene->add(mesh);
}

void Component::update() {

}

} // graphics
} // dioptre
