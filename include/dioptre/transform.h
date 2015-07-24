#ifndef DIOPTRE_TRANSFORM_H_
#define DIOPTRE_TRANSFORM_H_

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

namespace dioptre {

class Transform {
public:
  Transform();

  // Translation
  glm::vec3 getPosition() { return position_; }
  void setPosition(glm::float32 x, glm::float32 y, glm::float32 z);
  void translateX(glm::float32 x);
  void translateY(glm::float32 y);
  void translateZ(glm::float32 z);
  void translate(glm::vec3);

  // Scale
  void setScale(glm::float32 x, glm::float32 y, glm::float32 z);

  // Rotation
  glm::quat getOrientation() { return quaternion_; }

  void rotateX(glm::float32 angle);
  void rotateY(glm::float32 angle);
  void rotateZ(glm::float32 angle);

  void setUp(glm::vec3 up) { up_ = up; }

  virtual void lookAt(glm::float32 x, glm::float32 y, glm::float32 z);

  virtual void setMatrix(glm::mat4 matrix) {
    matrix_ = matrix;
  }
  glm::mat4 getMatrix();

protected:
  bool matrixNeedsUpdating_;
  void rotateOnAxis(glm::float32 angle, glm::vec3 axis);
  virtual void updateMatrix();

  glm::vec3 position_;
  glm::vec3 scale_;
  glm::quat quaternion_;

  glm::vec3 up_;
  glm::vec3 right_;
  glm::vec3 forward_;

  glm::mat4 matrix_;
}; // Transform

} // dioptre

#endif // DIOPTRE_TRANSFORM_H_
