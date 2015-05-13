#ifndef DIOPTRE_GRAPHICS_TRANSFORM_H_
#define DIOPTRE_GRAPHICS_TRANSFORM_H_

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

namespace dioptre {
namespace graphics {

class Transform {
public:
  Transform();

  // Translation
  void setPosition(glm::float32 x, glm::float32 y, glm::float32 z);
  void translateX(glm::float32 x);
  void translateY(glm::float32 y);
  void translateZ(glm::float32 z);
  void translate(glm::vec3);

  // Scale
  void setScale(glm::float32 x, glm::float32 y, glm::float32 z);

  // Rotation
  void rotateX(glm::float32 angle);
  void rotateY(glm::float32 angle);
  void rotateZ(glm::float32 angle);

  void lookAt(glm::float32 x, glm::float32 y, glm::float32 z);

  glm::mat4 getMatrix();

private:
  void rotateOnAxis(glm::float32 angle, glm::vec3 axis);

  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;
  glm::quat quaternion_;

  glm::vec3 up_;
  glm::vec3 right_;
  glm::vec3 forward_;

  glm::mat4 matrix_;
}; // Transform

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_TRANSFORM_H_
