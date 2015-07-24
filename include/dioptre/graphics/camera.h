#ifndef DIOPTRE_GRAPHICS_CAMERA_H_
#define DIOPTRE_GRAPHICS_CAMERA_H_

#include "dioptre/state.h"
#include "dioptre/camera_transform.h"
#include "glm/mat4x4.hpp"

namespace dioptre {
namespace graphics {

// Possibly abstract
class Camera {
public:
  Camera();
  glm::mat4 getProjectionMatrix();
  CameraTransform* getTransform() { return state_->getCurrent(); }

  State<CameraTransform>* getState() { return state_; }
  void makeCurrent() { state_->makeCurrent(); }

protected:
  State<CameraTransform>* state_;

  glm::mat4 projectionMatrix_;
  virtual void updateProjectionMatrix() = 0;
}; // Camera

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_CAMERA_H_
