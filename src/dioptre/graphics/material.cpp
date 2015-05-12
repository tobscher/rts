#include "dioptre/graphics/material.h"

namespace dioptre {
namespace graphics {

bool Material::isInitialized() {
  return isInitialized_;
}

void Material::setIsInitialized(bool value) {
  isInitialized_ = value;
}

} // graphics
} // dioptre
