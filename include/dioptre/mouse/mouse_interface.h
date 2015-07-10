#ifndef DIOPTRE_MOUSE_MOUSE_INTERFACE_H_
#define DIOPTRE_MOUSE_MOUSE_INTERFACE_H_

#include "position.h"
#include "dioptre/module.h"
#include "glm/vec2.hpp"

namespace dioptre {
namespace mouse {

/*
 * Abstract base class for mouse handling service.
 */
class MouseInterface : public dioptre::Module {
public:
  virtual ~MouseInterface() {}

  /*
   * setPosition sets the x and y position of the cursor.
   * This normally happens within a callback of the window system.
   */
  void setPosition(double x, double y);

  /**
   * getX returns the horizontal position of the mouse cursor.
   */
  double getX();

  /**
   * getY returns the vertical position of the mouse cursor.
   */
  double getY();

  /**
   * getPosition returns the position of the mouse cursor.
   */
  Position getPosition();

  /**
   * Returns a value that indicates if the mouse has moved yet.
   */
  bool hasMovedYet();

private:
  Position position_;
  bool moved_;
}; // MouseInterface

} // mouse
} // dioptre

#endif // DIOPTRE_MOUSE_MOUSE_INTERFACE_H_
