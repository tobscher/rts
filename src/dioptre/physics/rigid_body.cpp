#include "dioptre/physics/rigid_body.h"
#include "dioptre/math/id.h"

namespace dioptre {
namespace physics {

RigidBody::RigidBody(Shape* shape) :
  id_(dioptre::math::Id::next()),
  isInitialized_(false),
  position_(0.0f),
  shape_(shape),
  mass_(0),
  inertia_(0.0f) {
}

void RigidBody::translateX(glm::float32 x) {
  position_.x += x;
}

void RigidBody::translateY(glm::float32 y) {
  position_.y += y;
}

void RigidBody::translateZ(glm::float32 z) {
  position_.z += z;
}

} // physics
} // dioptre
