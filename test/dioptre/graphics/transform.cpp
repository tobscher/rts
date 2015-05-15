#include <gtest/gtest.h>
#include "dioptre/graphics/transform.h"

using dioptre::graphics::Transform;

TEST(Transform, Defaults) {
  Transform t;
  glm::mat4 expected;

  EXPECT_EQ(t.getMatrix(), expected);
}

TEST(Transform, SetPosition) {
  Transform t;
  t.setPosition(1,2,5);

  auto m = t.getMatrix();
  glm::mat4 expected;

  EXPECT_EQ(m[3][0], 1);
  EXPECT_EQ(m[3][1], 2);
  EXPECT_EQ(m[3][2], 5);
}
