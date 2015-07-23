#ifndef DIOPTRE_GRAPHICS_CAMERA_H_
#define DIOPTRE_GRAPHICS_CAMERA_H_

#include "object.h"
#include "dioptre/camera_transform.h"
#include "glm/mat4x4.hpp"

namespace dioptre {
namespace graphics {

// Possibly abstract
class Camera : public Object {
public:
  Camera();
  glm::mat4 getProjectionMatrix();
  CameraTransform* getTransform() { return transform_; }

protected:
  glm::mat4 projectionMatrix_;
  virtual void updateProjectionMatrix() = 0;

  CameraTransform* transform_;
}; // Camera

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_CAMERA_H_
