#include "dioptre/graphics/triangle_geometry.h"

namespace dioptre {
namespace graphics {

TriangleGeometry::TriangleGeometry(glm::vec3 a, glm::vec3 b, glm::vec3 c) {
  vertices_.push_back(a);
  vertices_.push_back(b);
  vertices_.push_back(c);
}

}
}
