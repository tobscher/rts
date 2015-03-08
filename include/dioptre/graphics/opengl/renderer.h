#ifndef DIOPTRE_GRAPHICS_OPENGL_RENDERER_
#define DIOPTRE_GRAPHICS_OPENGL_RENDERER_

#include "dioptre/graphics/renderer_interface.h"
#include "dioptre/window/window_interface.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class Renderer : public dioptre::graphics::RendererInterface {
public:
  Renderer(dioptre::window::WindowInterface* window);

  int Initialize();
  void Resize(int width, int height);
  void Render();

private:
  dioptre::window::WindowInterface* window_;
};

}
}
}

#endif
