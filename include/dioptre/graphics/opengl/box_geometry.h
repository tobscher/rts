#ifndef DIOPTRE_GRAPHICS_OPENGL_BOX_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_OPENGL_BOX_GEOMETRY_H_

#include "dioptre/graphics/box_geometry.h"
#include "dioptre/graphics/opengl/buffer_manager.h"
#include "dioptre/graphics/opengl.h"

#include <memory>

namespace dioptre {
namespace graphics {
namespace opengl {

class BoxGeometry : public dioptre::graphics::BoxGeometry {
public:
  BoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth);

  void initialize();
  void update();
  void destroy();

private:
  std::unique_ptr<dioptre::graphics::opengl::BufferManager> bufferManager_;
}; // BoxGeometry

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_BOX_GEOMETRY_H_
