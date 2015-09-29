#ifndef DIOPTRE_KEYBOARD_HANDLERS_TOGGLE_DEBUG_H_
#define DIOPTRE_KEYBOARD_HANDLERS_TOGGLE_DEBUG_H_

#include "dioptre/keyboard/keys.h"
#include "dioptre/keyboard/key_handler_interface.h"

namespace dioptre {
namespace keyboard {
namespace handlers {

/*
 * Keyboard handler to toggle the debug mode when pressed.
 */
class ToggleDebug : public dioptre::keyboard::KeyHandlerInterface {
public:
  /*
   * handles returns d to listen to that key.
   */
  dioptre::keyboard::Key handles();

  /*
   * Notifies services to turn on debug.
   */
  void update();
}; // ToggleDebug

} // handlers
} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_HANDLERS_TOGGLE_DEBUG_H_
