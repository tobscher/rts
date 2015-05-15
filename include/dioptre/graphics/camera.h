#ifndef DIOPTRE_GRAPHICS_CAMERA_H_
#define DIOPTRE_GRAPHICS_CAMERA_H_

#include "object.h"

namespace dioptre {
namespace graphics {

// Possibly abstract
class Camera : public Object {
public:
  glm::mat4 getProjectionMatrix();

protected:
  glm::mat4 projectionMatrix_;

  virtual void updateProjectionMatrix() = 0;
}; // Camera

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_CAMERA_H_
