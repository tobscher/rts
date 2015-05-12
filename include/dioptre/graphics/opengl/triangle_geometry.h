#ifndef DIOPTRE_GRAPHICS_OPENGL_TRIANGLE_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_OPENGL_TRIANGLE_GEOMETRY_H_

#include "dioptre/graphics/triangle_geometry.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class TriangleGeometry : public dioptre::graphics::TriangleGeometry {
public:
  TriangleGeometry(glm::vec3 a, glm::vec3 b, glm::vec3 c);

  void initialize();
  void update();
  void destroy();

private:
  GLuint vertexBuffer_;
}; // TriangleGeometry

}
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_TRIANGLE_GEOMETRY_H_
