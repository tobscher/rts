#include "dioptre/physics/rigid_body.h"
#include "dioptre/math/id.h"

namespace dioptre {
namespace physics {

RigidBody::RigidBody(Shape* shape) :
  id_(dioptre::math::Id::next()),
  isInitialized_(false),
  shape_(shape),
  mass_(0),
  inertia_(0.0f) {
}

} // physics
} // dioptre
