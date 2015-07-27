#ifndef DIOPTRE_GRAPHICS_ORTHOGRAPHIC_CAMERA_H_
#define DIOPTRE_GRAPHICS_ORTHOGRAPHIC_CAMERA_H_

#include "camera.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class OrthographicCamera : public Camera {
public:
  OrthographicCamera(glm::float32 left, glm::float32 right, glm::float32 bottom, glm::float32 top, glm::float32 near, glm::float32 far);

private:
  glm::float32 left_;
  glm::float32 right_;
  glm::float32 bottom_;
  glm::float32 top_;
  glm::float32 near_;
  glm::float32 far_;

  void updateProjectionMatrix();
}; // OrthographicCamera

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_ORTHOGRAPHIC_CAMERA_H_
