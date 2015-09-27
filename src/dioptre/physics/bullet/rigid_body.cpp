#include "dioptre/physics/bullet/rigid_body.h"

namespace dioptre {
namespace physics {
namespace bullet {

RigidBody::RigidBody(dioptre::physics::Shape *shape,
                     dioptre::Transform *transform)
    : dioptre::physics::RigidBody(shape, transform) {}

int RigidBody::initialize() {
  auto component = getComponent();
  auto object = component->getObject();
  auto orientation = transform_->getOrientation();
  auto position = transform_->getPosition();
  auto bulletShape = dynamic_cast<dioptre::physics::bullet::Shape *>(shape_);
  btCollisionShape *boxCollisionShape = bulletShape->getCollisionShape();

  btDefaultMotionState *motionstate = new btDefaultMotionState(btTransform(
      btQuaternion(orientation.x, orientation.y, orientation.z, orientation.w),
      btVector3(position.x, position.y, position.z)));

  btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
      mass_, // mass, in kg. 0 -> Static object, will never move.
      motionstate,
      boxCollisionShape,                            // collision shape of body
      btVector3(inertia_.x, inertia_.y, inertia_.z) // local inertia
      );

  rigidBody_ = new btRigidBody(rigidBodyCI);
  rigidBody_->setUserPointer(object);

  return 0;
}

void RigidBody::setTransform(dioptre::Transform *transform) {
  dioptre::physics::RigidBody::setTransform(transform);

  auto orientation = transform->getOrientation();
  auto position = transform->getPosition();
  auto motionState = rigidBody_->getMotionState();
  auto worldTransform = rigidBody_->getWorldTransform();
  worldTransform.setOrigin(btVector3(position.x, position.y, position.z));
  worldTransform.setRotation(
      btQuaternion(orientation.x, orientation.y, orientation.z, orientation.w));

  motionState->setWorldTransform(worldTransform);
  rigidBody_->setMotionState(motionState);
}

} // bullet
} // physics
} // dioptre
