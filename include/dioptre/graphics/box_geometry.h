#ifndef DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_

#include "geometry.h"

namespace dioptre {
namespace graphics {

class BoxGeometry : public Geometry {
public:
  BoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth);
  virtual ~BoxGeometry() {}

private:
  void addPlane(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
}; // BoxGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_
