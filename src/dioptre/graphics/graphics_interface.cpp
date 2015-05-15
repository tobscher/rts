#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/perspective_camera.h"

namespace dioptre {
namespace graphics {

GraphicsInterface::GraphicsInterface() :
  scene_(new Scene()),
  camera_(new PerspectiveCamera(45.0, 800/600, 0.1, 100))
{
  camera_->getTransform()->setPosition(0,0,5);
}

void GraphicsInterface::update() {
  render(scene_.get(), camera_.get());
}

Scene* GraphicsInterface::getScene() {
  return scene_.get();
}

} // graphics
} // dioptre
