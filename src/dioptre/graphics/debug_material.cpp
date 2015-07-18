#include "dioptre/graphics/debug_material.h"

namespace dioptre {
namespace graphics {

void DebugMaterial::setColor(color color) {
  color_ = color;
}

color DebugMaterial::getColor() {
  return color_;
}

} // graphics
} // dioptre
