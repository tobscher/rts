#include "dioptre/locator.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/window/null/window.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/null/graphics.h"

namespace dioptre {

dioptre::window::null::Window Locator::nullWindowService_;
dioptre::graphics::null::Graphics Locator::nullGraphicsService_;

dioptre::Module* Locator::instances_[dioptre::Module::M_MAX_ENUM];
dioptre::Module* Locator::defaults_[dioptre::Module::M_MAX_ENUM];

void Locator::initialize() {
  instances_[Module::M_WINDOW]   = defaults_[Module::M_WINDOW]   = &nullWindowService_;
  instances_[Module::M_GRAPHICS] = defaults_[Module::M_GRAPHICS] = &nullGraphicsService_;
}

void Locator::provide(Module::ModuleType type, Module *instance) {
  if (instance == nullptr) {
    instances_[type] = defaults_[type];
  } else {
    instances_[type] = instance;
  }
}

}
