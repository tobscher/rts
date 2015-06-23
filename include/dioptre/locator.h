#ifndef DIOPTRE_LOCATOR_H_
#define DIOPTRE_LOCATOR_H_

#include "window/window_interface.h"
#include "window/null/window.h"
#include "graphics/graphics_interface.h"
#include "graphics/null/graphics.h"
#include "keyboard/keyboard_interface.h"
#include "keyboard/null/keyboard.h"
#include "filesystem/filesystem_interface.h"
#include "filesystem/null/filesystem.h"

#include "dioptre/module.h"

namespace dioptre {

class Locator
{
public:
  static void initialize();
  static void provide(Module::ModuleType type, Module *instance);

  template <typename T>
  static T* getInstance(Module::ModuleType type) {
    return (T*)instances_[type];
  }

private:
  static dioptre::window::null::Window nullWindowService_;
  static dioptre::graphics::null::Graphics nullGraphicsService_;
  static dioptre::keyboard::null::Keyboard nullKeyboardService_;
  static dioptre::filesystem::null::Filesystem nullFilesystemService_;

  static Module* defaults_[Module::M_MAX_ENUM];
  static Module* instances_[Module::M_MAX_ENUM];
}; // Locator

} // dioptre

#endif // DIOPTRE_LOCATOR_H_
