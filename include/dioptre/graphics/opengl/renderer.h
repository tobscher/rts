#ifndef DIOPTRE_GRAPHICS_OPENGL_RENDERER_
#define DIOPTRE_GRAPHICS_OPENGL_RENDERER_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/renderer_interface.h"
#include "dioptre/window/window_interface.h"

// An array of 3 vectors which represents 3 vertices
static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

namespace dioptre {
namespace graphics {
namespace opengl {

class Renderer : public dioptre::graphics::RendererInterface {
public:
  Renderer(dioptre::window::WindowInterface* window);

  int Initialize();
  void Resize(int width, int height);
  void Render();
  void Destroy();

private:
  dioptre::window::WindowInterface* window_;
  GLuint vertexArrayId_;
  GLuint vertexBuffer_;
  GLuint programId_;
};

}
}
}

#endif
