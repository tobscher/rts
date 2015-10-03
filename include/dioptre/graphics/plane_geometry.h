#ifndef DIOPTRE_GRAPHICS_PLANE_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_PLANE_GEOMETRY_H_

#include "geometry.h"

namespace dioptre {
namespace graphics {

class PlaneGeometry : public Geometry {
public:
  PlaneGeometry(glm::float32 width, glm::float32 depth);
  virtual ~PlaneGeometry() {}

  glm::float32 getWidth();
  glm::float32 getDepth();

private:
  glm::float32 width_;
  glm::float32 depth_;
}; // PlaneGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_PLANE_GEOMETRY_H_
