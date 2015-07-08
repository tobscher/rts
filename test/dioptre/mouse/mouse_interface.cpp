#include <gtest/gtest.h>
#include "dioptre/mouse/mouse_interface.h"

class DummyMouse : public dioptre::mouse::MouseInterface {
  int initialize() { return 0; }
  void destroy() { }
};

TEST(Mouse, Position) {
  auto mouse = new DummyMouse();
  mouse->setPosition(13,37);

  EXPECT_EQ(mouse->getX(), 13);
  EXPECT_EQ(mouse->getY(), 37);

  auto position = mouse->getPosition();
  EXPECT_EQ(position.x, 13);
  EXPECT_EQ(position.y, 37);
}
