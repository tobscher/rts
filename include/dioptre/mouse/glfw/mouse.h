#ifndef DIOPTRE_MOUSE_GLFW_MOUSE_H_
#define DIOPTRE_MOUSE_GLFW_MOUSE_H_

#include <GLFW/glfw3.h>
#include "dioptre/mouse/mouse_interface.h"

namespace dioptre {
namespace mouse {
namespace glfw {

class Mouse : public dioptre::mouse::MouseInterface {
public:
  /*
   * Binds the mouse input
   */
  int initialize();

  /**
   * Destroys the mouse service.
   */
  void destroy();
}; // Mouse

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

} // glfw
} // mouse
} // dioptre

#endif // DIOPTRE_MOUSE_GLFW_MOUSE_H_
