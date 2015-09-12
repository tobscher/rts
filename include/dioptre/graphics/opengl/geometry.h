#ifndef DIOPTRE_GRAPHICS_OPENGL_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_OPENGL_GEOMETRY_H_

#include "dioptre/graphics/geometry.h"
#include "dioptre/graphics/opengl/buffer_manager.h"
#include "dioptre/graphics/opengl.h"

#include <memory>

namespace dioptre {
namespace graphics {
namespace opengl {

class Geometry : public dioptre::graphics::Geometry {
public:
  explicit Geometry(GLenum drawMode);

  void initialize();
  void update();
  void destroy();

private:
  std::unique_ptr<dioptre::graphics::opengl::BufferManager> bufferManager_;
  GLenum drawMode_;
}; // Geometry

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_GEOMETRY_H_
