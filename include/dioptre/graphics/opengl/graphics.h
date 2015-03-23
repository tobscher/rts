#ifndef DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_
#define DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/window/window_interface.h"

namespace dioptre {
namespace graphics {
namespace opengl {

/**
 * Class to render 3D graphics via OpenGL.
 */
class Graphics : public dioptre::graphics::GraphicsInterface {
public:
  /**
   * Initializes the OpenGL graphics context.
   */
  int initialize();

  /**
   * Handles window resizing, e.g. changing viewport.
   */
  void resize(int width, int height);

  /**
   * Renders the current scene graph to the screen.
   */
  void render();

  /**
   * Destroys the current 3D context.
   */
  void destroy();

private:
  GLuint vertexArrayId_;
  GLuint vertexBuffer_;
  GLuint programId_;
}; // Graphics

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_
