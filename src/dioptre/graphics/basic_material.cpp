#include "dioptre/graphics/basic_material.h"

namespace dioptre {
namespace graphics {

void BasicMaterial::setColor(color color) {
  color_ = color;
}

color BasicMaterial::getColor() {
  return color_;
}

void BasicMaterial::setTexture(dioptre::graphics::Texture* texture) {
  texture_ = texture;
}

dioptre::graphics::Texture* BasicMaterial::getTexture() {
  return texture_;
}

} // graphics
} // dioptre
