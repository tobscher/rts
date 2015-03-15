#ifndef DIOPTRE_GRAPHICS_OPENGL_RENDERER_H_
#define DIOPTRE_GRAPHICS_OPENGL_RENDERER_H_

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

/**
 * Class to render 3D graphics via OpenGL.
 */
class Renderer : public dioptre::graphics::RendererInterface {
public:
  Renderer(dioptre::window::WindowInterface* window);

  /**
   * Initializes the OpenGL graphics context.
   */
  int Initialize();

  /**
   * Handles window resizing, e.g. changing viewport.
   */
  void Resize(int width, int height);

  /**
   * Renders the current scene graph to the screen.
   */
  void Render();

  /**
   * Destroys the current 3D context.
   */
  void Destroy();

private:
  dioptre::window::WindowInterface* window_;
  GLuint vertexArrayId_;
  GLuint vertexBuffer_;
  GLuint programId_;
}; // Renderer

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_RENDERER_H_
