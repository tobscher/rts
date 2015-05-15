#include "dioptre/graphics/camera.h"

namespace dioptre {
namespace graphics {

glm::mat4 Camera::getProjectionMatrix() {
  return projectionMatrix_;
}

} // graphics
} // dioptre
