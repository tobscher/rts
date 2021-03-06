#ifndef DIOPTRE_KEYBOARD_GLFW_KEYBOARD_H_
#define DIOPTRE_KEYBOARD_GLFW_KEYBOARD_H_

#include <GLFW/glfw3.h>
#include <map>

#include "dioptre/keyboard/keyboard_interface.h"

namespace dioptre {
namespace keyboard {
namespace glfw {

/*
 * Keyboard class handles keyboard input via GLFW.
 */
class Keyboard : public dioptre::keyboard::KeyboardInterface {
public:
  /*
   * Binds the keyboard input
   */
  int initialize();

  /**
   * Destroys the keyboard service.
   */
  void destroy();

  /**
   * Map to retrieve the correct Key from the GLFW representation
   * of keys.
   */
  static dioptre::keyboard::Key map(int key);

private:
  static std::map<int, dioptre::keyboard::Key> keyMap_;
}; // Keyboard

/*
 * Method to handle key events.
 */
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

} // glfw
} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_GLFW_KEYBOARD_H_
