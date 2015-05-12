#ifndef DIOTRE_GRAPHICS_BASIC_MATERIAL_H_
#define DIOTRE_GRAPHICS_BASIC_MATERIAL_H_

#include "material.h"

namespace dioptre {
namespace graphics {

class BasicMaterial : public Material {
public:
  void setColor(color color);
  color getColor();

protected:
  color color_;
}; // BasicMaterial

} // graphics
} // dioptre

#endif
