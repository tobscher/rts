#include "dioptre/physics/component.h"
#include "dioptre/locator.h"

namespace dioptre {
namespace physics {

Component::Component(RigidBody* rigidBody) :
  dioptre::ComponentInterface("dioptre.physics.component"),
  rigidBody_(rigidBody)
{
  auto physicsService = dioptre::Locator::getInstance<PhysicsInterface>(dioptre::Module::M_PHYSICS);
  auto world = physicsService->getWorld();
  world->add(rigidBody);
}

void Component::update() {
}

Component::~Component() {
  delete rigidBody_;
}

} // physics
} // dioptre
