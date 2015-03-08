#ifndef DIOPTRE_WINDOW_GLFW_WINDOW_
#define DIOPTRE_WINDOW_GLFW_WINDOW_

#include <GLFW/glfw3.h>

#include "dioptre/window/window_interface.h"

namespace dioptre {
namespace window {
namespace glfw {

class Window : public dioptre::window::WindowInterface {
public:
  Window();

  int create();
  void destroy();
  bool shouldClose();
  void swapBuffers();

private:
  GLFWwindow* glfwWindow_;
};

}
}
}

#endif
