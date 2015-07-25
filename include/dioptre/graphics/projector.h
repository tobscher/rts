#ifndef DIOPTRE_GRAPHICS_PROJECTOR_H_
#define DIOPTRE_GRAPHICS_PROJECTOR_H_

#include "dioptre/graphics/camera_transform.h"

namespace dioptre {
namespace graphics {

class Projector {
public:
  Projector(glm::float32 fov, glm::float32 aspect, glm::float32 near, glm::float32 far);

  glm::mat4 getProjectionMatrix();
  CameraTransform* getTransform();

private:
  glm::float32 fov_;
  glm::float32 aspect_;
  glm::float32 near_;
  glm::float32 far_;

  void updateProjectionMatrix();
  glm::mat4 projectionMatrix_;

  CameraTransform* transform_;
}; // Projector

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_PROJECTOR_H_
