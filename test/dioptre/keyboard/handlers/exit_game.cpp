#include <gtest/gtest.h>
#include <iostream>

#include "dioptre/locator.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/keyboard/keyboard_interface.h"
#include "dioptre/keyboard/handlers/exit_game.h"

using dioptre::keyboard::KeyboardInterface;
using dioptre::window::WindowInterface;

class MockKeyboard : public KeyboardInterface {
  int initialize() {
    return 0;
  }

  void destroy() {
  }
};

TEST(KeyboardExitGameHandler, ShouldClose) {
  dioptre::Locator::initialize();

  MockKeyboard* mockKeyboard = new MockKeyboard();
  dioptre::Locator::provide(dioptre::Module::M_KEYBOARD, mockKeyboard);

  auto keyboard = dioptre::Locator::getInstance<KeyboardInterface>(dioptre::Module::M_KEYBOARD);
  auto window = dioptre::Locator::getInstance<WindowInterface>(dioptre::Module::M_WINDOW);

  dioptre::keyboard::handlers::ExitGame* exitGameHandler = new dioptre::keyboard::handlers::ExitGame();
  keyboard->registerKeyHandler(exitGameHandler);

  EXPECT_FALSE(window->shouldClose());
  keyboard->press(dioptre::keyboard::KEY_ESCAPE);
  EXPECT_TRUE(window->shouldClose());
}
