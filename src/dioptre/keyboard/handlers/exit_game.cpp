#include "exit_game.h"
#include "dioptre/locator.h"
#include "dioptre/keyboard/keys.h"

namespace dioptre {
namespace keyboard {
namespace handlers {

dioptre::keyboard::Key ExitGame::handles() {
  return dioptre::keyboard::KEY_ESCAPE;
}

void ExitGame::update() {
  auto window = dioptre::Locator::getInstance<dioptre::window::WindowInterface>(dioptre::Module::M_WINDOW);
  window->setShouldClose(true);
}

}
}
}
