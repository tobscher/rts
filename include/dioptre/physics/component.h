#ifndef DIOPTRE_PHYSICS_COMPONENT_H_
#define DIOPTRE_PHYSICS_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/physics/rigid_body.h"

namespace dioptre {
namespace physics {

class Component : public dioptre::ComponentInterface {
public:
  Component(RigidBody* rigidBody);
  ~Component();

  void update();

private:
  RigidBody* rigidBody_;
};

}
}

#endif // DIOPTRE_GRAPHICS_COMPONENT_H_
