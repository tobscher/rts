#ifndef DIOPTRE_GRAPHICS_CAMERA_TRANSFORM_H_
#define DIOPTRE_GRAPHICS_CAMERA_TRANSFORM_H_

#include "glm/glm.hpp"
#include "dioptre/transform.h"

namespace dioptre {
namespace graphics {

class CameraTransform : public Transform {
public:
  void lookAt(glm::vec3 target);
  void lookAt(glm::float32 x, glm::float32 y, glm::float32 z);

  glm::mat4 getMatrixWorldInverse();

  void setMatrix(glm::mat4 &matrix);

protected:
  void updateMatrix();

private:
  glm::mat4 matrixWorldInverse_;
}; // CameraTransform

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_CAMERA_TRANSFORM_H_
