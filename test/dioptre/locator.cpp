#include "gtest/gtest.h"

#include "dioptre/locator.h"
#include "dioptre/module.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/graphics/graphics_interface.h"

using dioptre::window::WindowInterface;
using dioptre::graphics::GraphicsInterface;

TEST(Locator, DefaultWindow) {
  dioptre::Locator::initialize();
  WindowInterface* window = dioptre::Locator::getInstance<WindowInterface>(dioptre::Module::M_WINDOW);

  EXPECT_EQ(window->create(), 0);
}

TEST(Locator, DefaultGraphics) {
  dioptre::Locator::initialize();
  GraphicsInterface* graphics = dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS);

  EXPECT_EQ(graphics->Initialize(), 0);
}

class MockGraphics : public GraphicsInterface {
public:
  int Initialize() { return 1337; }
  void Resize(int width, int height) {  }
  void Render() { }
  void Destroy() { }
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

  EXPECT_EQ(dioptre::Locator::getInstance<GraphicsInterface>(dioptre::Module::M_GRAPHICS), nullGraphics);
}
