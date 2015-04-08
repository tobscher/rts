#ifndef DIOPTRE_KEYBOARD_HANDLERS_EXIT_GAME_H_
#define DIOPTRE_KEYBOARD_HANDLERS_EXIT_GAME_H_

#include "dioptre/keyboard/keys.h"
#include "dioptre/keyboard/key_handler_interface.h"

namespace dioptre {
namespace keyboard {
namespace handlers {

class ExitGame : public dioptre::keyboard::KeyHandlerInterface {
public:
  dioptre::keyboard::Key handles();
  void update();
};

}
}
}

#endif // DIOPTRE_KEYBOARD_HANDLERS_EXIT_GAME_H_
