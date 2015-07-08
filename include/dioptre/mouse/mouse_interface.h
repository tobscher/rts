#ifndef DIOPTRE_MOUSE_MOUSE_INTERFACE_H_
#define DIOPTRE_MOUSE_MOUSE_INTERFACE_H_

#include "position.h"
#include "dioptre/module.h"
#include "glm/vec2.hpp"

namespace dioptre {
namespace mouse {

class MouseInterface : public dioptre::Module {
public:
  virtual ~MouseInterface() {}
  void setPosition(double x, double y);

  double getX();
  double getY();
  Position getPosition();

private:
  Position position_;
}; // MouseInterface

} // mouse
} // dioptre

#endif // DIOPTRE_MOUSE_MOUSE_INTERFACE_H_
