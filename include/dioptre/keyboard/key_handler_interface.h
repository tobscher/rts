#ifndef DIOPTRE_KEYBOARD_KEY_HANDLER_INTERFACE_H_
#define DIOPTRE_KEYBOARD_KEY_HANDLER_INTERFACE_H_

#include "keys.h"

namespace dioptre {
namespace keyboard {

class KeyHandlerInterface {
public:
  virtual ~KeyHandlerInterface() {}
  virtual Key handles() = 0;
  virtual void update() = 0;
};

}
}

#endif // DIOPTRE_KEYBOARD_KEY_HANDLER_INTERFACE_H_
