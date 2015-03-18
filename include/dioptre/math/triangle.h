#ifndef DIOPTRE_MATH_TRIANGLE_
#define DIOPTRE_MATH_TRIANGLE_

#include <vector>

#include "glm/glm.hpp"

namespace dioptre {
namespace math {

/**
 * Represents a triangle.
 */
class Triangle {
public:
  /**
   * Initializes a new triangle.
   */
  Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c);

  /**
   * Returns the first point of the triangle.
   */
  glm::vec3 a();

  /**
   * Returns the second point of the triangle.
   */
  glm::vec3 b();

  /**
   * Returns the third point of the triangle.
   */
  glm::vec3 c();

  std::vector<glm::vec3> data();

private:
  glm::vec3 a_;
  glm::vec3 b_;
  glm::vec3 c_;
}; // Triangle

} // math
} // dioptre

#endif // DIOPTRE_MATH_TRIANGLE_
