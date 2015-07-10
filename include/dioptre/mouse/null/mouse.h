#ifndef DIOPTRE_MOUSE_NULL_MOUSE_H_
#define DIOPTRE_MOUSE_NULL_MOUSE_H_

#include "dioptre/mouse/mouse_interface.h"

namespace dioptre {
namespace mouse {
namespace null {

/*
 * Null Mouse service.
 */
class Mouse : public dioptre::mouse::MouseInterface {
public:
  int initialize() { return 0; }
  void destroy() {}
}; // Mouse

} // null
} // mouse
} // dioptre

#endif // DIOPTRE_MOUSE_NULL_MOUSE_H_
