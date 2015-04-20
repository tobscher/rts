#include <iostream>

#include "dioptre/keyboard/keyboard_interface.h"
#include "dioptre/debug.h"

namespace dioptre {
namespace keyboard {

void KeyboardInterface::press(Key key) {
  pressed_.push_back(key);

  auto handlers = keyHandlers_.find(key);
  if (handlers == keyHandlers_.end()) return;

  for (auto it = handlers->second.begin();
      it != handlers->second.end();
      it++) {
    (*it)->update();
  }
}

void KeyboardInterface::registerKeyHandler(KeyHandlerInterface* handler) {
  auto key = handler->handles();
  auto &handlers = keyHandlers_[key];
  handlers.push_back(handler);
}

} // keyboard
} // dioptre
