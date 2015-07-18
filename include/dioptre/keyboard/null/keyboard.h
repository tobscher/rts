#ifndef DIOPTRE_KEYBOARD_NULL_KEYBOARD_H_
#define DIOPTRE_KEYBOARD_NULL_KEYBOARD_H_

#include "dioptre/keyboard/keyboard_interface.h"

namespace dioptre {
namespace keyboard {
namespace null {

/*
 * Null keyboard input.
 */
class Keyboard : public dioptre::keyboard::KeyboardInterface {
public:
  /*
   * Null initializer.
   */
  int initialize() { return 0; }

  /*
   * Null destroy.
   */
  void destroy() {}
}; // Keyboard

} // null
} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_NULL_KEYBOARD_H_
