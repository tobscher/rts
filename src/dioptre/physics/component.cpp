#include "dioptre/physics/component.h"
#include "dioptre/locator.h"

namespace dioptre {
namespace physics {

Component::Component(RigidBody *rigidBody)
    : dioptre::ComponentInterface("dioptre.physics.component"),
      rigidBody_(rigidBody) {
  auto physicsService = dioptre::Locator::getInstance<PhysicsInterface>(
      dioptre::Module::M_PHYSICS);
  auto world = physicsService->getWorld();
  world->add(rigidBody);

  rigidBody->setComponent(this);

  transformObserver_ = new dioptre::physics::TransformObserver(this);
}

int Component::initialize() {
  dioptre::ComponentInterface::initialize();

  rigidBody_->initialize();

  auto transform = object_->getTransform();
  transform->attach(transformObserver_);

  return 0;
}

void Component::update() {}

Component::~Component() { delete rigidBody_; }

} // physics
} // dioptre
