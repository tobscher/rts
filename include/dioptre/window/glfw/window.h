#ifndef DIOPTRE_WINDOW_GLFW_WINDOW_H_
#define DIOPTRE_WINDOW_GLFW_WINDOW_H_

#include <GLFW/glfw3.h>

#include "dioptre/window/window_interface.h"

namespace dioptre {
namespace window {
namespace glfw {

/**
 * Implementation of the WindowInterface that creates a window via
 * GLFW.
 */
class Window : public dioptre::window::WindowInterface {
public:
  Window();

  int initialize();
  void destroy();
  int shouldClose();
  void swapBuffers();

private:
  GLFWwindow* glfwWindow_;
}; // Window

} // glfw
} // window
} // dioptre

#endif // DIOPTRE_WINDOW_GLFW_WINDOW_H_
