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
  void setShouldClose(bool value);
  void swapBuffers();

  GLFWwindow* GetWindow();

private:
  GLFWwindow* glfwWindow_;
  GLFWmonitor* glfwMonitor_;
  const GLFWvidmode* glfwVideoMode_;
}; // Window

} // glfw
} // window
} // dioptre

#endif // DIOPTRE_WINDOW_GLFW_WINDOW_H_
