#include <stdlib.h>
#include <stdio.h>

#include "dioptre/window/glfw/window.h"
#include "dioptre/graphics/opengl/renderer.h"

/* void error_callback(int error, const char* description) { */
/*   fputs(description, stderr); */
/* } */

/* static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) { */
/*   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) */
/*     glfwSetWindowShouldClose(window, GL_TRUE); */
/* } */

int main(void) {
  dioptre::window::glfw::Window* window(new dioptre::window::glfw::Window());
  window->create();
  dioptre::graphics::opengl::Renderer renderer(window);

  renderer.Initialize();

  while(!window->shouldClose()) {
    renderer.Render();
    window->swapBuffers();
  }

  window->destroy();
  exit(EXIT_SUCCESS);
}
