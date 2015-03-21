#ifndef DIOPTRE_WINDOW_WINDOW_INTERFACE_H_
#define DIOPTRE_WINDOW_WINDOW_INTERFACE_H_

#include "dioptre/module.h"

namespace dioptre {
namespace window {

/**
 * WindowInterface describes the creation and destruction
 * of windows.
 */
class WindowInterface : public Module {
public:
  virtual ~WindowInterface() { }

  /**
   * Should create the window for the current platform.
   */
  virtual int create() = 0;

  /**
   * Should create the current window.
   */
  virtual void destroy() = 0;

  /**
   * Should indicate whether the windows should be closed.
   */
  virtual int shouldClose() = 0;

  /**
   * Should swap back and front buffer for rendering.
   */
  virtual void swapBuffers() = 0;
}; // WindowInterface

} // window
} // dioptre

#endif // DIOPTRE_WINDOW_WINDOW_INTERFACE_H_
