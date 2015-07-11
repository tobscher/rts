#include "edge_scroll_component.h"
#include "dioptre/locator.h"

#include <iostream>

namespace objects {
namespace components {

EdgeScrollComponent::EdgeScrollComponent() :
  ComponentInterface("components.edge_scroll"),
  scrollSpeed_(1.0),
  scrollThreshold_(1)
{
}

// TODO(tobscher) use delta
void EdgeScrollComponent::update() {
  auto windowService = dioptre::Locator::getInstance<dioptre::window::WindowInterface>(dioptre::Module::M_WINDOW);
  auto mouseService = dioptre::Locator::getInstance<dioptre::mouse::MouseInterface>(dioptre::Module::M_MOUSE);
  auto graphicsService = dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto camera = graphicsService->getCamera();

  auto size = windowService->getSize();
  auto position = mouseService->getPosition();

  if (!mouseService->hasMovedYet()) return;

  double top = scrollThreshold_;
  double left = scrollThreshold_;
  double right = size.width - scrollThreshold_;
  double bottom = size.height - scrollThreshold_;

  glm::vec3 translation;

  if (position.x < left) {
    translation.x -= scrollSpeed_;
  }

  if (position.x > right) {
    translation.x += scrollSpeed_;
  }

  if (position.y < top) {
    translation.z -= scrollSpeed_;
  }

  if (position.y > bottom) {
    translation.z += scrollSpeed_;
  }

  camera->getTransform()->translate(translation);
}

} // components
} // objects
