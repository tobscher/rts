#ifndef DIOPTRE_PHYSICS_RIGID_BODY_H_
#define DIOPTRE_PHYSICS_RIGID_BODY_H_

#include "dioptre/component_interface.h"
#include "dioptre/physics/shape.h"
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

namespace dioptre {
namespace physics {

class RigidBody {
public:
  RigidBody(Shape* shape);

  glm::vec3 getInertia() { return inertia_; }
  float getMass() { return mass_; }
  bool isInitialized() { return isInitialized_; }
  Shape* getShape() { return shape_; }

  int getId() { return id_; }

  dioptre::ComponentInterface* getComponent() { return component_; }
  void setComponent(dioptre::ComponentInterface* component) { component_ = component; }

private:
  int id_;
  bool isInitialized_;

  Shape* shape_;
  float mass_;
  glm::vec3 inertia_;

  dioptre::ComponentInterface* component_;
}; // RigidBody

} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_RIGID_BODY_H_
