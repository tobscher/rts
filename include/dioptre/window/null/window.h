#ifndef DIOPTRE_WINDOW_NULL_WINDOW_H_
#define DIOPTRE_WINDOW_NULL_WINDOW_H_

#include "dioptre/window/window_interface.h"

namespace dioptre {
namespace window {
namespace null {

class Window : public dioptre::window::WindowInterface {
public:
  Window() :
    shouldClose_(false) { }
  int initialize() { return 0; }
  void destroy() { }
  int shouldClose() { return shouldClose_; }
  void setShouldClose(bool state) { shouldClose_ = state; }
  void swapBuffers() {  }
  Size getSize() { return Size(800, 600); }

private:
  bool shouldClose_;
}; // Window

} // null
} // window
} // dioptre

#endif // DIOPTRE_WINDOW_NULL_WINDOW_H_
