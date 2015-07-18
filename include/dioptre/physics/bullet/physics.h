#ifndef DIOPTRE_PHYSICS_BULLET_PHYSICS_H_
#define DIOPTRE_PHYSICS_BULLET_PHYSICS_H_

#include <memory>

#include "btBulletDynamicsCommon.h"
#include "dioptre/physics/physics_interface.h"
#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/debug_drawer.h"

namespace dioptre {
namespace physics {
namespace bullet {

class Physics : public dioptre::physics::PhysicsInterface {
public:
  int initialize();
  void destroy();
  void simulate();

  void initializeWorld();
  void initializeRigidBody(dioptre::physics::RigidBody* rigidBody);
  void castRay(dioptre::mouse::Position position);
  void debug();

private:
  std::unique_ptr<btBroadphaseInterface> broadphase_;
  std::unique_ptr<btDefaultCollisionConfiguration> collisionConfiguration_;
  std::unique_ptr<btCollisionDispatcher> dispatcher_;
  std::unique_ptr<btSequentialImpulseConstraintSolver> solver_;
  std::unique_ptr<btDiscreteDynamicsWorld> dynamicsWorld_;

  std::unique_ptr<DebugDrawer> debugDrawer_;

  std::vector<btRigidBody*> rigidBodies_;
}; // Physics

} // bullet
} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_BULLET_PHYSICS_H_
