#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/perspective_camera.h"

namespace dioptre {
namespace graphics {

// TODO(Tobscher) Use aspect ratio from window
// TODO(Tobscher) Add method to define camera
GraphicsInterface::GraphicsInterface() :
  Module("dioptre.graphics"),
  scene_(new Scene()),
  camera_(new PerspectiveCamera(28.0, 1280.0/800.0, 1, 1000))
{
  auto transform = camera_->getTransform();

  transform->setPosition(0,100,25);
  transform->lookAt(0.0f, 0.0f, 0.0f);
}

void GraphicsInterface::update() {
}

Scene* GraphicsInterface::getScene() {
  return scene_.get();
}

Camera* GraphicsInterface::getCamera() {
  return camera_.get();
}

void GraphicsInterface::setProjector(Projector* projector) {
  projector_ = projector;
}

} // graphics
} // dioptre
