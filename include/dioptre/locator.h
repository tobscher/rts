#ifndef DIOPTRE_LOCATOR_H_
#define DIOPTRE_LOCATOR_H_

#include "window/window_interface.h"
#include "window/null/window.h"
#include "graphics/graphics_interface.h"
#include "graphics/null/graphics.h"

namespace dioptre {

class Locator
{
public:
  static void initialize() {
    windowService_ = &nullWindowService_;
    graphicsService_ = &nullGraphicsService_;
  }

  static dioptre::window::WindowInterface& getWindow() {
    return *windowService_;
  }

  static dioptre::graphics::GraphicsInterface& getGraphics() {
    return *graphicsService_;
  }

private:
  // window
  static dioptre::window::WindowInterface* windowService_;
  static dioptre::window::null::Window nullWindowService_;

  // graphics
  static dioptre::graphics::GraphicsInterface* graphicsService_;
  static dioptre::graphics::null::Graphics nullGraphicsService_;
}; // Locator

} // dioptre

#endif // DIOPTRE_LOCATOR_H_
