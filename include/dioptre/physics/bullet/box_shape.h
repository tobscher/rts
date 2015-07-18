#ifndef DIOPTRE_PHYSICS_BULLET_BOX_SHAPE_H_
#define DIOPTRE_PHYSICS_BULLET_BOX_SHAPE_H_

#include "dioptre/physics/shape.h"
#include "dioptre/physics/bullet/shape.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace physics {
namespace bullet {

class BoxShape : public dioptre::physics::Shape,
                 public dioptre::physics::bullet::Shape {
public:
  BoxShape(glm::float32 width, glm::float32 height, glm::float32 depth);
  ShapeType getShapeType() { return dioptre::physics::SHAPE_BOX; }

private:
  glm::float32 width_;
  glm::float32 height_;
  glm::float32 depth_;
}; // BoxShape

} // bullet
} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_BULLET_BOX_SHAPE_H_
