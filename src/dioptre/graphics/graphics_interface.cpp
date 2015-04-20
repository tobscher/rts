#include "dioptre/graphics/graphics_interface.h"

namespace dioptre {
namespace graphics {

GraphicsInterface::GraphicsInterface() :
  scene_(new Scene()),
  camera_(new Camera()) {
}

void GraphicsInterface::update() {
  render();
}

Scene* GraphicsInterface::getScene() {
  return scene_.get();
}

} // graphics
} // dioptre
