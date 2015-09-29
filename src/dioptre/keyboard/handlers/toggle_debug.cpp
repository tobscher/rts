#include "dioptre/keyboard/handlers/toggle_debug.h"
#include "dioptre/locator.h"
#include "dioptre/keyboard/keys.h"

namespace dioptre {
namespace keyboard {
namespace handlers {

dioptre::keyboard::Key ToggleDebug::handles() {
  return dioptre::keyboard::KEY_D;
}

void ToggleDebug::update() {
  auto physics =
      dioptre::Locator::getInstance<dioptre::physics::PhysicsInterface>(
          dioptre::Module::M_PHYSICS);

  physics->toggleDebug();
}

} // handlers
} // keyboard
} // dioptre
