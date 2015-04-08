#ifndef DIOPTRE_WINDOW_NULL_WINDOW_H_
#define DIOPTRE_WINDOW_NULL_WINDOW_H_

#include "dioptre/window/window_interface.h"

namespace dioptre {
namespace window {
namespace null {

class Window : public dioptre::window::WindowInterface {
public:
  int initialize() { return 0; }
  void destroy() { }
  int shouldClose() { return shouldClose_; }
  void setShouldClose(bool state) { shouldClose_ = state; }
  void swapBuffers() {  }

private:
  bool shouldClose_ = false;
}; // Window

} // null
} // window
} // dioptre

#endif // DIOPTRE_WINDOW_NULL_WINDOW_H_
