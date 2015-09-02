#ifndef DIOPTRE_GRAPHICS_OPENGL_TEXT_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_OPENGL_TEXT_GEOMETRY_H_

#include "dioptre/graphics/text_geometry.h"
#include "dioptre/graphics/opengl/buffer_manager.h"
#include "dioptre/graphics/opengl/atlas.h"
#include "dioptre/graphics/opengl.h"

#include <memory>

namespace dioptre {
namespace graphics {
namespace opengl {

class TextGeometry : public dioptre::graphics::TextGeometry {
public:
  TextGeometry(std::string text, dioptre::graphics::opengl::Atlas* atlas);

  void initialize();
  void update();
  void destroy();

  void setText(std::string text);


private:
  std::unique_ptr<dioptre::graphics::opengl::BufferManager> bufferManager_;
  dioptre::graphics::opengl::Atlas* atlas_;

  void calculate();
}; // TextGeometry

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_TEXT_GEOMETRY_H_
