#ifndef DIOPTRE_GRAPHICS_TRIANGLE_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_TRIANGLE_GEOMETRY_H_

#include "geometry.h"

namespace dioptre {
namespace graphics {

class TriangleGeometry : public Geometry {
public:
  TriangleGeometry(glm::vec3 a, glm::vec3 b, glm::vec3 c);
  ~TriangleGeometry() {}
}; // TriangleGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_TRIANGLE_GEOMETRY_H_
