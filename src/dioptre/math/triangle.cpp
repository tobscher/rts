#include "dioptre/math/triangle.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace math {

Triangle::Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c) :
  a_(a),
  b_(b),
  c_(c)
{
}

glm::vec3 Triangle::a() {
  return a_;
}

glm::vec3 Triangle::b() {
  return b_;
}

glm::vec3 Triangle::c() {
  return c_;
}

std::vector<glm::vec3> Triangle::data() {
  std::vector<glm::vec3> data{a_, b_, c_};
  return data;
}

}
}
