#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/perspective_camera.h"

namespace dioptre {
namespace graphics {

// TODO(Tobscher) use aspect ratio from window
GraphicsInterface::GraphicsInterface() :
  scene_(new Scene()),
  camera_(new PerspectiveCamera(45.0, 800/600, 1, 10000))
{
  camera_->getTransform()->setPosition(0,100,50);
  camera_->getTransform()->lookAt(0.0f, 0.0f, 0.0f);
}

void GraphicsInterface::update() {
  render();
}

Scene* GraphicsInterface::getScene() {
  return scene_.get();
}

} // graphics
} // dioptre
