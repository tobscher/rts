#include "dioptre/mouse/mouse_interface.h"

namespace dioptre {
namespace mouse {

void MouseInterface::setPosition(double x, double y) {
  moved_ = true;

  position_.x = x;
  position_.y = y;
}

double MouseInterface::getX() {
  return position_.x;
}

double MouseInterface::getY() {
  return position_.y;
}

Position MouseInterface::getPosition() {
  return position_;
}

bool MouseInterface::hasMovedYet() {
  return moved_;
}

} // mouse
} // dioptre
