#ifndef DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_
#define DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_

#include <map>

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/debug.h"
#include "dioptre/graphics/opengl/geometry.h"
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
   * Initializes the current scene.
   */
  void initializeScene();

  /**
   * Handles window resizing, e.g. changing viewport.
   */
  void resize(int width, int height);

  /**
   * Renders the current scene graph to the screen.
   */
  void render(const double alpha);

  /**
   * Renders the given scene graph with the current camera.
   */
  void renderScene(Scene *scene, Camera *camera, float alpha);

  /**
   * Destroys the current 3D context.
   */
  void destroy();

  /**
   * Destroys the given scene.
   */
  void destroyScene(Scene *scene);

private:
  void initializeMesh(Mesh *mesh);
  void renderMesh(Mesh *mesh);
  void destroyMesh(Mesh *mesh);

  dioptre::graphics::opengl::Debug *debug_;

  GLuint vertexArrayId_;
}; // Graphics

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_
