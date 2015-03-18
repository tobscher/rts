#include <unittest++/UnitTest++.h>
#include "glm/glm.hpp"
#include "dioptre/math/triangle.h"

TEST(Triangle_initialization) {
  glm::vec3 a(0.1, 0.2, 0.3);
  glm::vec3 b(0.4, 0.5, 0.6);
  glm::vec3 c(0.7, 0.8, 0.9);

  dioptre::math::Triangle triangle(a, b, c);

  CHECK(a == triangle.a());
  CHECK(b == triangle.b());
  CHECK(c == triangle.c());
}
