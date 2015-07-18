#ifndef DIOPTRE_GRAPHICS_LINE_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_LINE_GEOMETRY_H_

#include "geometry.h"

namespace dioptre {
namespace graphics {

class LineGeometry : public Geometry {
public:
  LineGeometry(glm::vec3 from, glm::vec3 to);
  virtual ~LineGeometry() {}

private:
  glm::vec3 from_;
  glm::vec3 to_;
}; // BoxGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_LINE_GEOMETRY_H_
