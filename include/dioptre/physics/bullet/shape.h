#ifndef DIOPTRE_PHYSICS_BULLET_SHAPE_H_
#define DIOPTRE_PHYSICS_BULLET_SHAPE_H_

#include "btBulletCollisionCommon.h"

namespace dioptre {
namespace physics {
namespace bullet {

class Shape {
public:
  ~Shape() { delete collisionShape_; }
  virtual btCollisionShape* getCollisionShape() { return collisionShape_; };

protected:
  btCollisionShape* collisionShape_;
}; // Shape

} // bullet
} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_BULLET_SHAPE_H_
