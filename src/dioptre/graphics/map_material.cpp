#include "dioptre/graphics/map_material.h"

namespace dioptre {
namespace graphics {

void MapMaterial::setTexture(dioptre::graphics::Texture* texture) {
  texture_ = texture;
}

dioptre::graphics::Texture* MapMaterial::getTexture() {
  return texture_;
}

} // graphics
} // dioptre
