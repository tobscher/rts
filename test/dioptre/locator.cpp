#include "gtest/gtest.h"

#include "dioptre/locator.h"

TEST(Locator, DefaultWindow) {
  dioptre::Locator::initialize();
  dioptre::window::WindowInterface& window = dioptre::Locator::getWindow();

  EXPECT_EQ(window.create(), 0);
}
