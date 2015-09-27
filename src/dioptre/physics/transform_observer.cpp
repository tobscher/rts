#include "dioptre/physics/transform_observer.h"
#include "dioptre/physics/component.h"

namespace dioptre {
namespace physics {

TransformObserver::TransformObserver(dioptre::physics::Component *component)
    : component_(component) {}

void TransformObserver::changed(dioptre::Transform *transform) {
  auto rigidBody = component_->getRigidBody();
  rigidBody->setTransform(transform);
}

} // physics
} // dioptre
