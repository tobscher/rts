#include "dioptre/graphics/orthographic_camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <math.h>

namespace dioptre {
namespace graphics {

OrthographicCamera::OrthographicCamera(glm::float32 left, glm::float32 right, glm::float32 bottom, glm::float32 top, glm::float32 near, glm::float32 far) :
  left_(left),
  right_(right),
  bottom_(bottom),
  top_(top),
  near_(near),
  far_(far)
{
  updateProjectionMatrix();
}

void OrthographicCamera::updateProjectionMatrix() {
  projectionMatrix_ = glm::ortho(left_, right_, bottom_, top_, near_, far_);
}

} // graphics
} // dioptre
