#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/perspective_camera.h"

namespace dioptre {
namespace graphics {

// TODO(Tobscher) use aspect ratio from window
GraphicsInterface::GraphicsInterface() :
  Module("dioptre.graphics"),
  scene_(new Scene()),
  camera_(new PerspectiveCamera(28.0, 800/600, 1, 10000))
{
  camera_->getTransform()->setPosition(0,100,25);
  camera_->getTransform()->lookAt(0.0f, 0.0f, 0.0f);
}

void GraphicsInterface::update() {
  render();
}

Scene* GraphicsInterface::getScene() {
  return scene_.get();
}

Camera* GraphicsInterface::getCamera() {
  return camera_.get();
}

} // graphics
} // dioptre
