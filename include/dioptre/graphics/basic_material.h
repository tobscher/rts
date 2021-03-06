#ifndef DIOTRE_GRAPHICS_BASIC_MATERIAL_H_
#define DIOTRE_GRAPHICS_BASIC_MATERIAL_H_

#include "material.h"
#include "dioptre/graphics/texture.h"

namespace dioptre {
namespace graphics {

class BasicMaterial : public Material {
public:
  BasicMaterial();
  virtual ~BasicMaterial() {}

  void setColor(color color);
  color getColor();

  void setTexture(dioptre::graphics::Texture* texture);
  dioptre::graphics::Texture* getTexture();

protected:
  color color_;
  dioptre::graphics::Texture* texture_;
}; // BasicMaterial

} // graphics
} // dioptre

#endif
