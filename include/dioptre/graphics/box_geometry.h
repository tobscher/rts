#ifndef DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_

#include "geometry.h"

namespace dioptre {
namespace graphics {

class BoxGeometry : public Geometry {
public:
  BoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth);
  virtual ~BoxGeometry() {}

  glm::float32 getWidth() { return width_; }
  glm::float32 getHeight() { return height_; }
  glm::float32 getDepth() { return depth_; }

private:
  glm::float32 width_;
  glm::float32 height_;
  glm::float32 depth_;
}; // BoxGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_
