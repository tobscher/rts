#include "dioptre/graphics/text_material.h"

namespace dioptre {
namespace graphics {

void TextMaterial::setColor(color color) {
  color_ = color;
}

color TextMaterial::getColor() {
  return color_;
}

} // graphics
} // dioptre
