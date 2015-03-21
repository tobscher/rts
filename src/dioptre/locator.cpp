#include "dioptre/locator.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/window/null/window.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/null/graphics.h"

namespace dioptre {

dioptre::window::null::Window Locator::nullWindowService_;
dioptre::window::WindowInterface* Locator::windowService_;

dioptre::graphics::null::Graphics Locator::nullGraphicsService_;
dioptre::graphics::GraphicsInterface* Locator::graphicsService_;

}
