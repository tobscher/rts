#include <ostream>
#include <GL/glew.h>

#include "dioptre/graphics/opengl/renderer.h"

namespace dioptre {
namespace graphics {
namespace opengl {

Renderer::Renderer(dioptre::window::WindowInterface* window)
  : window_(window) {
}

int Renderer::Initialize() {
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

  return 0;
}

void Renderer::Resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport( 0, 0, width, height);
}

void Renderer::Render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}
}
}
