#ifndef DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_
#define DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_

#include <map>

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/debug_material.h"
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
   * Handles window resizing, e.g. changing viewport.
   */
  void resize(int width, int height);

  /**
   * Renders the current scene graph to the screen.
   */
  void render();

  void renderScene(Scene* scene);

  /**
   * Destroys the current 3D context.
   */
  void destroy();

  void destroyScene(Scene* scene);

  void resetDebug();

  void initializeScene();

  void addLine(glm::vec3 from, glm::vec3 to);

private:
  void initializeMesh(Mesh* mesh);
  void renderMesh(Mesh* mesh);
  void destroyMesh(Mesh* mesh);

  GLuint vertexArrayId_;

  DebugMaterial* debugMaterial_;
  Geometry* debugGeometry_;
}; // Graphics

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_GRAPHICS_H_
