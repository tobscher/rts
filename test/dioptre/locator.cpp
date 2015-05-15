#include "gtest/gtest.h"

#include "dioptre/locator.h"
#include "dioptre/module.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/keyboard/keyboard_interface.h"

using dioptre::window::WindowInterface;
using dioptre::graphics::GraphicsInterface;
using dioptre::keyboard::KeyboardInterface;

TEST(Locator, DefaultWindow) {
  dioptre::Locator::initialize();
  WindowInterface* window = dioptre::Locator::getInstance<WindowInterface>(dioptre::Module::M_WINDOW);

  EXPECT_EQ(window->initialize(), 0);
}

TEST(Locator, DefaultGraphics) {
  dioptre::Locator::initialize();
  GraphicsInterface* graphics = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);

  EXPECT_EQ(graphics->initialize(), 0);
}

TEST(Locator, DefaultKeyboard) {
  dioptre::Locator::initialize();
  KeyboardInterface* keyboard = dioptre::Locator::getInstance<KeyboardInterface>(dioptre::Module::M_KEYBOARD);

  EXPECT_EQ(keyboard->initialize(), 0);
}

class MockGraphics : public GraphicsInterface {
public:
  int initialize() { return 1337; }
  void resize(int width, int height) {  }
  void render(dioptre::graphics::Scene* scene, dioptre::graphics::Camera* camera) { }
  void destroy() { }
};

TEST(Locator, Provide) {
  dioptre::Locator::initialize();

  MockGraphics* mockGraphics = new MockGraphics();
  dioptre::Locator::provide(dioptre::Module::M_GRAPHICS, mockGraphics);

  EXPECT_EQ(dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS), mockGraphics);
}

TEST(Locator, ProvideNull) {
  dioptre::Locator::initialize();
  auto nullGraphics = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);

  MockGraphics* mockGraphics = new MockGraphics();
  dioptre::Locator::provide(dioptre::Module::M_GRAPHICS, mockGraphics);
  dioptre::Locator::provide(dioptre::Module::M_GRAPHICS, nullptr);

  // Setting it to nullptr does revert back to default
  EXPECT_EQ(dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS), nullGraphics);
}
