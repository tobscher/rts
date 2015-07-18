#ifndef DIOPTRE_PHYSICS_WORLD_H_
#define DIOPTRE_PHYSICS_WORLD_H_

#include "glm/vec3.hpp"
#include <vector>

#include "dioptre/physics/rigid_body.h"

namespace dioptre {
namespace physics {

class World {
public:
  World();
  glm::vec3 getGravity() { return gravity_; }

  void add(RigidBody* rigidBody) { rigidBodies_.push_back(rigidBody); }
  std::vector<RigidBody*>::iterator begin() { return rigidBodies_.begin(); }
  std::vector<RigidBody*>::iterator end() { return rigidBodies_.end(); }

private:
  glm::vec3 gravity_;
  std::vector<RigidBody*> rigidBodies_;
}; // World

} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_WORLD_H_
