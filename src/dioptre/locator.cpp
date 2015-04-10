#include "dioptre/locator.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/window/null/window.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/null/graphics.h"
#include "dioptre/keyboard/keyboard_interface.h"
#include "dioptre/keyboard/null/keyboard.h"

namespace dioptre {

dioptre::window::null::Window Locator::nullWindowService_;
dioptre::graphics::null::Graphics Locator::nullGraphicsService_;
dioptre::keyboard::null::Keyboard Locator::nullKeyboardService_;

dioptre::Module* Locator::instances_[dioptre::Module::M_MAX_ENUM];
dioptre::Module* Locator::defaults_[dioptre::Module::M_MAX_ENUM];

void Locator::initialize() {
  instances_[Module::M_WINDOW]   = defaults_[Module::M_WINDOW]   = &nullWindowService_;
  instances_[Module::M_GRAPHICS] = defaults_[Module::M_GRAPHICS] = &nullGraphicsService_;
  instances_[Module::M_KEYBOARD] = defaults_[Module::M_KEYBOARD] = &nullKeyboardService_;
}

void Locator::provide(Module::ModuleType type, Module *instance) {
  if (instance == nullptr) {
    instances_[type] = defaults_[type];
  } else {
    instances_[type] = instance;
  }
}

} // dioptre
