#include "dioptre/graphics/transform_observer.h"
#include "dioptre/graphics/component.h"

namespace dioptre {
namespace graphics {

TransformObserver::TransformObserver(dioptre::graphics::Component *component)
    : component_(component) {}

void TransformObserver::changed(dioptre::Transform *transform) {
  auto projector = component_->getProjector();
  auto oldTransform = projector->getTransform();

  if (oldTransform == nullptr)
    return;

  projector->getState()->getCurrent()->setPosition(
      transform->getPosition().x, oldTransform->getPosition().y,
      transform->getPosition().z);
}

} // graphics
} // dioptre
