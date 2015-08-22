#ifndef DIOTRE_GRAPHICS_TEXT_MATERIAL_H_
#define DIOTRE_GRAPHICS_TEXT_MATERIAL_H_

#include "material.h"

namespace dioptre {
namespace graphics {

class TextMaterial : public Material {
public:
  virtual ~TextMaterial() {}

  void setColor(color color);
  color getColor();

protected:
  color color_;
}; // TextMaterial

} // graphics
} // dioptre

#endif // DIOTRE_GRAPHICS_TEXT_MATERIAL_H_
