#ifndef DIOPTRE_PHYSICS_PHYSICS_INTERFACE_H_
#define DIOPTRE_PHYSICS_PHYSICS_INTERFACE_H_

#include "dioptre/module.h"
#include "dioptre/mouse/mouse_interface.h"
#include "dioptre/physics/world.h"

#include <memory>

namespace dioptre {
namespace physics {

class PhysicsInterface : public dioptre::Module {
public:
  PhysicsInterface();
  virtual ~PhysicsInterface() {}

  World* getWorld() { return world_.get(); }

  virtual void simulate() = 0;
  virtual void initializeWorld() = 0;
  virtual void castRay(dioptre::mouse::Position position) = 0;
  virtual void debug() = 0;

protected:
  std::unique_ptr<World> world_;
}; // PhysicsInterface

} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_PHYSICS_INTERFACE_H_
