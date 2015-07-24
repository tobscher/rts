#include "dioptre/graphics/projector.h"
#include "dioptre/camera_transform.h"

#include "glm/gtc/matrix_transform.hpp"

#include <math.h>

namespace dioptre {
namespace graphics {

Projector::Projector(glm::float32 fov, glm::float32 aspect, glm::float32 near, glm::float32 far) :
  fov_(fov),
  aspect_(aspect),
  near_(near),
  far_(far),
  transform_(new CameraTransform())
{
  updateProjectionMatrix();
}

void Projector::updateProjectionMatrix() {
  glm::float32 ymax = near_ * tan(glm::radians(fov_*0.5));
  glm::float32 ymin = -ymax;
  glm::float32 xmin = ymin * aspect_;
  glm::float32 xmax = ymax * aspect_;

  projectionMatrix_ = glm::frustum(xmin, xmax, ymin, ymax, near_, far_);
}

} // graphics
} // dioptre
