#include "dioptre/graphics/layer.h"
#include "dioptre/graphics/perspective_camera.h"

namespace dioptre {
namespace graphics {

// TODO(Tobscher) Add method to define camera
// TODO(Tobscher) Use aspect ratio from window
// new PerspectiveCamera(28.0, 1280.0/800.0, 1, 1000)
// auto transform = camera_->getTransform();

// transform->setPosition(0,100,15);
// transform->lookAt(0.0f, 0.0f, 0.0f);
Layer::Layer(Scene* scene, Camera* camera) :
  scene_(scene),
  camera_(camera) {
}

Scene* Layer::getScene() {
  return scene_.get();
}

Camera* Layer::getCamera() {
  return camera_.get();
}


} // graphics
} // dioptre
