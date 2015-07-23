#include "dioptre/transform.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include "dioptre/debug.h"

namespace dioptre {

Transform::Transform() :
  matrixNeedsUpdating_(false),
  position_(0.0f),
  // quaternion_ == identity
  scale_(1.0f),
  up_(0.0f, 1.0f, 0.0f),
  right_(1.0f, 0.0f, 0.0f),
  forward_(0.0f, 0.0f, -1.0f)
  // matrix_ == identity
{
}

void Transform::setPosition(glm::float32 x, glm::float32 y, glm::float32 z) {
  position_ = glm::vec3(x, y, z);
  matrixNeedsUpdating_ = true;
}

void Transform::translateX(glm::float32 x) {
  position_.x += x;
  matrixNeedsUpdating_ = true;
}

void Transform::translateY(glm::float32 y) {
  position_.y += y;
  matrixNeedsUpdating_ = true;
}

void Transform::translateZ(glm::float32 z) {
  position_.z += z;
  matrixNeedsUpdating_ = true;
}

void Transform::translate(glm::vec3 v) {
  position_ += v;
  matrixNeedsUpdating_ = true;
}

void Transform::setScale(glm::float32 x, glm::float32 y, glm::float32 z) {
  scale_ = glm::vec3(x, y, z);
  matrixNeedsUpdating_ = true;
}

void Transform::rotateX(glm::float32 angle) {
  glm::vec3 axis(1.0f, 0.0f, 0.0f);
  rotateOnAxis(angle, axis);
}

void Transform::rotateY(glm::float32 angle) {
  glm::vec3 axis(0.0f, 1.0f, 0.0f);
  rotateOnAxis(angle, axis);
}

void Transform::rotateZ(glm::float32 angle) {
  glm::vec3 axis(0.0f, 0.0f, 1.0f);
  rotateOnAxis(angle, axis);
}

glm::mat4 Transform::getMatrix() {
  if (matrixNeedsUpdating_) {
    updateMatrix();
  }
  return matrix_;
}

void Transform::lookAt(glm::float32 x, glm::float32 y, glm::float32 z) {
  glm::vec3 target(x, y, z);
  matrix_ = glm::lookAt(position_, target, up_);
}

void Transform::rotateOnAxis(glm::float32 angle, glm::vec3 axis) {
  glm::quat q = glm::angleAxis(angle, axis);

  quaternion_ *= q;
  matrix_ *= glm::toMat4(q);
}

void Transform::updateMatrix() {
  glm::mat4 rotationMatrix = glm::toMat4(quaternion_);
  glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position_);
  glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale_);

  matrix_ = translationMatrix * rotationMatrix * scaleMatrix;
}

} // dioptre
