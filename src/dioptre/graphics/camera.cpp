#include "dioptre/camera_transform.h"
#include "dioptre/graphics/camera.h"

namespace dioptre {
namespace graphics {

Camera::Camera() :
  transform_(new dioptre::CameraTransform()) {

}

glm::mat4 Camera::getProjectionMatrix() {
  return projectionMatrix_;
}

} // graphics
} // dioptre
