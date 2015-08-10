#ifndef DIOPTRE_FONT_FONT_INTERFACE_H_
#define DIOPTRE_FONT_FONT_INTERFACE_H_

#include "dioptre/module.h"

namespace dioptre {
namespace font {

class FontInterface : public Module {
public:
  FontInterface() : Module("dioptre.font") {}
  virtual ~FontInterface() {}
}; // FontInterface

} // font
} // dioptre

#endif
