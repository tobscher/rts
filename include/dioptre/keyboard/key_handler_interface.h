#ifndef DIOPTRE_KEYBOARD_KEY_HANDLER_INTERFACE_H_
#define DIOPTRE_KEYBOARD_KEY_HANDLER_INTERFACE_H_

#include "keys.h"

namespace dioptre {
namespace keyboard {

/*
 * Interface describing key press events.
 */
class KeyHandlerInterface {
public:
  virtual ~KeyHandlerInterface() {}

  /**
   * Implementation should return the key it wants to respond to.
   */
  virtual Key handles() = 0;

  /**
   * Implementation should execute the code to when the actual key is pressed.
   */
  virtual void update() = 0;
}; // KeyHandlerInterface

} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_KEY_HANDLER_INTERFACE_H_
