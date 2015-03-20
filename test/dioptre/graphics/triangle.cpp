#include <gtest/gtest.h>
#include "glm/glm.hpp"
#include "dioptre/math/triangle.h"

TEST(Triangle, Initialization) {
  glm::vec3 a(0.1, 0.2, 0.3);
  glm::vec3 b(0.4, 0.5, 0.6);
  glm::vec3 c(0.7, 0.8, 0.9);

  dioptre::math::Triangle triangle(a, b, c);

  EXPECT_EQ(a, triangle.a());
  EXPECT_EQ(b, triangle.b());
  EXPECT_EQ(c, triangle.c());
}
