#ifndef DIOPTRE_KEYBOARD_HANDLERS_EXIT_GAME_H_
#define DIOPTRE_KEYBOARD_HANDLERS_EXIT_GAME_H_

#include "dioptre/keyboard/keys.h"
#include "dioptre/keyboard/key_handler_interface.h"

namespace dioptre {
namespace keyboard {
namespace handlers {

/*
 * Keyboard handler to exit the game when the ESC is pressed.
 */
class ExitGame : public dioptre::keyboard::KeyHandlerInterface {
public:
  /*
   * handles returns ESC to listen to that key.
   */
  dioptre::keyboard::Key handles();

  /*
   * Sends a signal to the window service that the window should be closed.
   */
  void update();
}; // ExitGame

} // handlers
} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_HANDLERS_EXIT_GAME_H_
