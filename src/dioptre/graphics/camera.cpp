#include "dioptre/graphics/camera.h"

namespace dioptre {
namespace graphics {

Camera::Camera() :
  state_(new State<dioptre::CameraTransform>()) {

}

glm::mat4 Camera::getProjectionMatrix() {
  return projectionMatrix_;
}

} // graphics
} // dioptre
