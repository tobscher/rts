#ifndef DIOPTRE_PHYSICS_COMPONENT_H_
#define DIOPTRE_PHYSICS_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/physics/rigid_body.h"
#include "dioptre/physics/transform_observer.h"

namespace dioptre {
namespace physics {

class Component : public dioptre::ComponentInterface {
public:
  explicit Component(RigidBody *rigidBody);
  ~Component();

  int initialize();
  void update();

  RigidBody *getRigidBody() { return rigidBody_; }

private:
  RigidBody *rigidBody_;
  dioptre::physics::TransformObserver *transformObserver_;
};

} // physics
} // dioptre

#endif // DIOPTRE_PHYSIC_COMPONENT_H_
