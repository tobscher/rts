#include "dioptre/graphics/basic_material.h"

namespace dioptre {
namespace graphics {

void BasicMaterial::setColor(color color) {
  color_ = color;
}

color BasicMaterial::getColor() {
  return color_;
}

} // graphics
} // dioptre
