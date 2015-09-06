#include "dioptre/locator.h"

namespace dioptre {

dioptre::window::null::Window Locator::nullWindowService_;
dioptre::graphics::null::Graphics Locator::nullGraphicsService_;
dioptre::keyboard::null::Keyboard Locator::nullKeyboardService_;
dioptre::mouse::null::Mouse Locator::nullMouseService_;
dioptre::time::null::Time Locator::nullTimeService_;
dioptre::physics::null::Physics Locator::nullPhysicsService_;

dioptre::Module* Locator::instances_[dioptre::Module::M_MAX_ENUM];
dioptre::Module* Locator::defaults_[dioptre::Module::M_MAX_ENUM];

void Locator::initialize() {
  instances_[Module::M_WINDOW]   = defaults_[Module::M_WINDOW]   = &nullWindowService_;
  instances_[Module::M_GRAPHICS] = defaults_[Module::M_GRAPHICS] = &nullGraphicsService_;
  instances_[Module::M_KEYBOARD] = defaults_[Module::M_KEYBOARD] = &nullKeyboardService_;
  instances_[Module::M_MOUSE] = defaults_[Module::M_MOUSE] = &nullMouseService_;
  instances_[Module::M_TIME] = defaults_[Module::M_TIME] = &nullTimeService_;
  instances_[Module::M_PHYSICS] = defaults_[Module::M_PHYSICS] = &nullPhysicsService_;
}

void Locator::provide(Module::ModuleType type, Module *instance) {
  if (instance == nullptr) {
    instances_[type] = defaults_[type];
  } else {
    instances_[type] = instance;
  }
}

} // dioptre
