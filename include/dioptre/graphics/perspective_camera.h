#ifndef DIOPTRE_GRAPHICS_PERSPECTIVE_CAMERA_H_
#define DIOPTRE_GRAPHICS_PERSPECTIVE_CAMERA_H_

#include "camera.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class PerspectiveCamera : public Camera {
public:
  PerspectiveCamera(glm::float32 fov, glm::float32 aspect, glm::float32 near, glm::float32 far);

private:
  glm::float32 fov_;
  glm::float32 aspect_;
  glm::float32 near_;
  glm::float32 far_;

  void updateProjectionMatrix();
}; // PerspectiveCamera

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_PERSPECTIVE_CAMERA_H_
