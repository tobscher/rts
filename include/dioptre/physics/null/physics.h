#ifndef DIOPTRE_PHYSICS_NULL_PHYSICS_H_
#define DIOPTRE_PHYSICS_NULL_PHYSICS_H_

#include "dioptre/physics/physics_interface.h"

namespace dioptre {
namespace physics {
namespace null {

class Physics : public dioptre::physics::PhysicsInterface {
  int initialize() { return 0; }
  void destroy() {}
  void simulate() {}
  void initializeWorld() {}
  void castRay(dioptre::mouse::Position position) {}
  void debug() {}
}; // Physics

} // null
} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_NULL_PHYSICS_H_
