#ifndef DIOPTRE_GRAPHICS_PROJECTOR_H_
#define DIOPTRE_GRAPHICS_PROJECTOR_H_

#include "dioptre/graphics/camera_transform.h"
#include "dioptre/graphics/mesh.h"

namespace dioptre {
namespace graphics {

class Component;
class Projector {
public:
  Projector(glm::float32 fov, glm::float32 aspect, glm::float32 near,
            glm::float32 far);

  glm::mat4 getProjectionMatrix();

  State<CameraTransform> *getState() { return state_; }
  CameraTransform *getTransform();
  void makeCurrent();

  Mesh *getTarget();
  void setTarget(Mesh *mesh);

private:
  Mesh *target_;

  glm::float32 fov_;
  glm::float32 aspect_;
  glm::float32 near_;
  glm::float32 far_;

  void updateProjectionMatrix();
  glm::mat4 projectionMatrix_;

  State<CameraTransform> *state_;
}; // Projector

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_PROJECTOR_H_
