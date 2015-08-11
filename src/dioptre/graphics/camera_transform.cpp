#include "dioptre/graphics/camera_transform.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include "dioptre/debug.h"

namespace dioptre {
namespace graphics {

void CameraTransform::lookAt(glm::float32 x, glm::float32 y, glm::float32 z) {
  glm::vec3 target(x, y, z);
  lookAt(target);
}

void CameraTransform::lookAt(glm::vec3 target) {
  matrixWorldInverse_ = glm::lookAt(position_, target, up_);
  matrix_ = glm::inverse(matrixWorldInverse_);

  quaternion_ = glm::toQuat(matrix_);
}

glm::mat4 CameraTransform::getMatrixWorldInverse() {
  if (matrixNeedsUpdating_) {
    updateMatrix();
  }
  return matrixWorldInverse_;
}

void CameraTransform::setMatrix(glm::mat4 &matrix) {
  matrix_ = matrix;
  matrixWorldInverse_ = glm::inverse(matrix);
}

void CameraTransform::updateMatrix() {
  Transform::updateMatrix();
  matrixWorldInverse_ = glm::inverse(matrix_);
}

} // graphics
} // dioptre
