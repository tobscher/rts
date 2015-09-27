#ifndef DIOPTRE_PHYSICS_BULLET_RIGID_BODY_H_
#define DIOPTRE_PHYSICS_BULLET_RIGID_BODY_H_

#include "dioptre/physics/rigid_body.h"
#include "dioptre/physics/bullet/shape.h"
#include "btBulletDynamicsCommon.h"

namespace dioptre {
namespace physics {
namespace bullet {

class RigidBody : public dioptre::physics::RigidBody {
public:
  explicit RigidBody(dioptre::physics::Shape *shape,
                     dioptre::Transform *transform);

  int initialize();
  void setTransform(dioptre::Transform *transform);

  btRigidBody *getBulletRigidBody() { return rigidBody_; }

private:
  btRigidBody *rigidBody_;
}; // RigidBody

} // bullet
} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_BULLET_RIGID_BODY_H_
