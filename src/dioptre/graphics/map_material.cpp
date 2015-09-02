#include "dioptre/graphics/map_material.h"

#include <iostream>

namespace dioptre {
namespace graphics {

void MapMaterial::setColor(color color) {
  color_ = color;
}

color MapMaterial::getColor() {
  return color_;
}

void MapMaterial::setTexture(dioptre::graphics::Texture* texture) {
  texture_ = texture;
}

dioptre::graphics::Texture* MapMaterial::getTexture() {
  return texture_;
}

} // graphics
} // dioptre
