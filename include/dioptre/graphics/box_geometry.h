#ifndef DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_

#include "geometry.h"
#include "bounding_box.h"

namespace dioptre {
namespace graphics {

class BoxGeometry : public Geometry {
public:
  BoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth);
  virtual ~BoxGeometry();

  glm::float32 getWidth();
  glm::float32 getHeight();
  glm::float32 getDepth();

  BoundingBox *getBoundingBox();

private:
  glm::float32 width_;
  glm::float32 height_;
  glm::float32 depth_;

  BoundingBox *boundingBox_;
}; // BoxGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_BOX_GEOMETRY_H_
