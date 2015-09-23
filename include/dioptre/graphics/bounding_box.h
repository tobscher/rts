#ifndef DIOPTRE_GRAPHICS_BOUNDING_BOX_H_
#define DIOPTRE_GRAPHICS_BOUNDING_BOX_H_

#include "glm/vec3.hpp"

namespace dioptre {
namespace graphics {

class BoundingBox {
public:
  BoundingBox(glm::vec3 min, glm::vec3 max);

  glm::vec3 getMin();
  glm::vec3 getMax();

private:
  glm::vec3 min_;
  glm::vec3 max_;
}; // BoundingBox

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_BOUNDING_BOX_H_
