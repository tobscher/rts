#include "dioptre/physics/physics_interface.h"

namespace dioptre {
namespace physics {

PhysicsInterface::PhysicsInterface() :
  Module("dioptre.physics"),
  world_(new World()) {

}

} // physics
} // dioptre
