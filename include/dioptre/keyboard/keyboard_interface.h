#ifndef DIOPTRE_KEYBOARD_KEYBOARD_INTERFACE_H_
#define DIOPTRE_KEYBOARD_KEYBOARD_INTERFACE_H_

#include "dioptre/module.h"

namespace dioptre {
namespace keyboard {

// Interface to handle keyboard input.
class KeyboardInterface : public dioptre::Module {
public:
  virtual ~KeyboardInterface() {}
}; // KeyboardInterface

} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_KEYBOARD_INTERFACE_H_
