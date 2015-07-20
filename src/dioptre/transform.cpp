#include "dioptre/transform.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include "dioptre/debug.h"

namespace dioptre {

Transform::Transform() :
  position_(0.0f),
  rotation_(0.0f),
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

  matrix_[3][0] = x;
  matrix_[3][1] = y;
  matrix_[3][2] = z;
}

void Transform::translateX(glm::float32 x) {
  position_.x += x;

  matrix_[3][0] = position_.x;
}

void Transform::translateY(glm::float32 y) {
  position_.y += y;

  matrix_[3][1] = position_.y;
}

void Transform::translateZ(glm::float32 z) {
  position_.z += z;

  matrix_[3][2] = position_.z;
}

void Transform::translate(glm::vec3 v) {
  position_ += v;

  matrix_[3][0] = position_.x;
  matrix_[3][1] = position_.y;
  matrix_[3][2] = position_.z;
}

void Transform::setScale(glm::float32 x, glm::float32 y, glm::float32 z) {
  scale_ = glm::vec3(x, y, z);

  matrix_[0][0] = x;
  matrix_[1][1] = y;
  matrix_[2][2] = z;
}

void Transform::rotateX(glm::float32 angle) {
  rotation_.x += angle;

  glm::vec3 axis(1.0f, 0.0f, 0.0f);
  rotateOnAxis(angle, axis);
}

void Transform::rotateY(glm::float32 angle) {
  rotation_.y += angle;

  glm::vec3 axis(0.0f, 1.0f, 0.0f);
  rotateOnAxis(angle, axis);
}

void Transform::rotateZ(glm::float32 angle) {
  rotation_.z += angle;

  glm::vec3 axis(0.0f, 0.0f, 1.0f);
  rotateOnAxis(angle, axis);
}

glm::mat4 Transform::getMatrix() {
  return matrix_;
}

void Transform::lookAt(glm::float32 x, glm::float32 y, glm::float32 z) {
  glm::vec3 target(x, y, z);

  matrix_ = glm::inverse(glm::lookAt(position_, target, up_));
  /* matrix_ = glm::lookAt(position_, target, up_); */
}

void Transform::rotateOnAxis(glm::float32 angle, glm::vec3 axis) {
  glm::quat q = glm::angleAxis(angle, axis);

  quaternion_ *= q;
  matrix_ *= glm::toMat4(q);
}

} // dioptre
