#ifndef DIOPTRE_PHYSICS_RIGID_BODY_H_
#define DIOPTRE_PHYSICS_RIGID_BODY_H_

#include "dioptre/physics/shape.h"
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

namespace dioptre {
namespace physics {

class RigidBody {
public:
  RigidBody(Shape* shape);

  glm::quat getOrientation() { return orientation_; }
  glm::vec3 getPosition() { return position_; }
  glm::vec3 getInertia() { return inertia_; }
  float getMass() { return mass_; }
  bool isInitialized() { return isInitialized_; }
  Shape* getShape() { return shape_; }

  void translateX(glm::float32 x);
  void translateY(glm::float32 y);
  void translateZ(glm::float32 z);

  int getId() { return id_; }

private:
  int id_;
  bool isInitialized_;

  glm::quat orientation_;
  glm::vec3 position_;
  Shape* shape_;
  float mass_;
  glm::vec3 inertia_;
}; // RigidBody

} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_RIGID_BODY_H_
