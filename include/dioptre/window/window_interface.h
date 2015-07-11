#ifndef DIOPTRE_WINDOW_WINDOW_INTERFACE_H_
#define DIOPTRE_WINDOW_WINDOW_INTERFACE_H_

#include "dioptre/module.h"
#include "size.h"

namespace dioptre {
namespace window {

/**
 * WindowInterface describes the creation and destruction
 * of windows.
 */
class WindowInterface : public Module {
public:
  WindowInterface() : Module("dioptre.window") {}
  virtual ~WindowInterface() { }

  /**
   * Should indicate whether the windows should be closed.
   */
  virtual int shouldClose() = 0;

  /**
   * Tells the window it should be closed.
   */
  virtual void setShouldClose(bool value) = 0;

  /**
   * Should swap back and front buffer for rendering.
   */
  virtual void swapBuffers() = 0;

  /**
   * Returns the dimensions of the screen.
   */
  virtual Size getSize() = 0;
}; // WindowInterface

} // window
} // dioptre

#endif // DIOPTRE_WINDOW_WINDOW_INTERFACE_H_
