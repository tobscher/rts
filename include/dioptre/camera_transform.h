#ifndef DIOPTRE_CAMERA_TRANSFORM_H_
#define DIOPTRE_CAMERA_TRANSFORM_H_

#include "glm/glm.hpp"
#include "dioptre/transform.h"

namespace dioptre {

class CameraTransform : public Transform {
public:
  void lookAt(glm::float32 x, glm::float32 y, glm::float32 z);
  glm::mat4 getMatrixWorldInverse() {
    if (matrixNeedsUpdating_) {
      updateMatrix();
    }
    return matrixWorldInverse_;
  }

protected:
  void updateMatrix();

private:
  glm::mat4 matrixWorldInverse_;
}; // CameraTransform

} // dioptre

#endif // DIOPTRE_CAMERA_TRANSFORM_H_
