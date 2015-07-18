#include "dioptre/physics/bullet/box_shape.h"

namespace dioptre {
namespace physics {
namespace bullet {

BoxShape::BoxShape(glm::float32 width, glm::float32 height, glm::float32 depth) :
  width_(width),
  height_(height),
  depth_(depth) {
  collisionShape_ = new btBoxShape(btVector3(width_, height_, depth_));
}

} // bullet
} // physics
} // dioptre
