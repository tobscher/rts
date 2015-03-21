#ifndef DIOPTRE_WINDOW_NULL_H_
#define DIOPTRE_WINDOW_NULL_H_

#include "dioptre/locator.h"
#include "dioptre/window/null/window.h"
#include "dioptre/window/window_interface.h"

namespace dioptre {

dioptre::window::null::Window Locator::nullWindowService_;
dioptre::window::WindowInterface* Locator::windowService_;

}

#endif
