#ifndef DIOTRE_GRAPHICS_MAP_MATERIAL_H_
#define DIOTRE_GRAPHICS_MAP_MATERIAL_H_

#include "material.h"
#include "dioptre/graphics/texture.h"

namespace dioptre {
namespace graphics {

class MapMaterial : public Material {
public:
  virtual ~MapMaterial() {}

  void setColor(color color);
  color getColor();

  void setTexture(dioptre::graphics::Texture* texture);
  dioptre::graphics::Texture* getTexture();

protected:
  color color_;
  dioptre::graphics::Texture* texture_;
}; // MapMaterial

} // graphics
} // dioptre

#endif
