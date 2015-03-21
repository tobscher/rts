#ifndef DIOPTRE_LOCATOR_H_
#define DIOPTRE_LOCATOR_H_

#include "window/window_interface.h"
#include "window/null/window.h"

namespace dioptre {

class Locator
{
public:
  static void initialize() {
    windowService_ = &nullWindowService_;
  }

  static dioptre::window::WindowInterface& getWindow() {
    return *windowService_;
  }

private:
  static dioptre::window::WindowInterface* windowService_;
  static dioptre::window::null::Window nullWindowService_;
}; // Locator

} // dioptre

#endif // DIOPTRE_LOCATOR_H_
