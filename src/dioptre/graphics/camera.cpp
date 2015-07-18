#include "dioptre/graphics/camera.h"

namespace dioptre {
namespace graphics {

Camera::Camera() :
  transform_(new dioptre::Transform()) {

}

glm::mat4 Camera::getProjectionMatrix() {
  return projectionMatrix_;
}

} // graphics
} // dioptre
