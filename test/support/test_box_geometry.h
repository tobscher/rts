#ifndef TEST_BOX_GEOMETRY_H_
#define TEST_BOX_GEOMETRY_H_

#include "dioptre/graphics/box_geometry.h"

class TestBoxGeometry : public dioptre::graphics::BoxGeometry {
public:
  TestBoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth)
      : dioptre::graphics::BoxGeometry(width, height, depth) {}

  void initialize() {}
  void update() {}
  void destroy() {}
}; // TestBoxGeometry

#endif // TEST_BOX_GEOMETRY_H_
