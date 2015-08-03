#include "dioptre/graphics/material.h"

namespace dioptre {
namespace graphics {

Material::Material() :
  isInitialized_(false) {
  logger_ = spdlog::get("dioptre");
}

bool Material::isInitialized() {
  return isInitialized_;
}

void Material::setIsInitialized(bool value) {
  isInitialized_ = value;
}

} // graphics
} // dioptre
