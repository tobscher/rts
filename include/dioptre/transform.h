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
  glm::vec3 getPosition();
  void setPosition(glm::float32 x, glm::float32 y, glm::float32 z);
  void translateX(glm::float32 x);
  void translateY(glm::float32 y);
  void translateZ(glm::float32 z);
  void translate(glm::vec3);

  // Scale
  void setScale(glm::float32 x, glm::float32 y, glm::float32 z);

  // Rotation
  glm::quat getOrientation();
  void rotateX(glm::float32 angle);
  void rotateY(glm::float32 angle);
  void rotateZ(glm::float32 angle);

  // Up
  void setUp(glm::vec3 up);

  // LookAt
  virtual void lookAt(glm::vec3 position);
  void lookAt(glm::float32 x, glm::float32 y, glm::float32 z);

  // Matrix
  virtual void setMatrix(glm::mat4 &matrix);
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
