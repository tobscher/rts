#ifndef DIOPTRE_KEYBOARD_KEYBOARD_INTERFACE_H_
#define DIOPTRE_KEYBOARD_KEYBOARD_INTERFACE_H_

#include <vector>
#include <map>

#include "dioptre/module.h"
#include "keys.h"
#include "key_handler_interface.h"

namespace dioptre {
namespace keyboard {

// Interface to handle keyboard input.
class KeyboardInterface : public dioptre::Module {
public:

  virtual ~KeyboardInterface() {}

  void registerKeyHandler(KeyHandlerInterface* handler);
  void press(Key key);

private:
  std::vector<Key> pressed_;
  std::map<Key, std::vector<KeyHandlerInterface*>> keyHandlers_;
}; // KeyboardInterface

} // keyboard
} // dioptre

#endif // DIOPTRE_KEYBOARD_KEYBOARD_INTERFACE_H_
