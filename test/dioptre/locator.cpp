#include "gtest/gtest.h"

#include "dioptre/locator.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/graphics/graphics_interface.h"

TEST(Locator, DefaultWindow) {
  dioptre::Locator::initialize();
  dioptre::window::WindowInterface& window = dioptre::Locator::getWindow();

  EXPECT_EQ(window.create(), 0);
}

TEST(Locator, DefaultGraphics) {
  dioptre::Locator::initialize();
  dioptre::graphics::GraphicsInterface& graphics = dioptre::Locator::getGraphics();

  EXPECT_EQ(graphics.Initialize(), 0);
}
