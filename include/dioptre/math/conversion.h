#ifndef DIOPTRE_MATH_CONVERSION_H_
#define DIOPTRE_MATH_CONVERSION_H_

#include <math.h>
#include "glm/glm.hpp"

namespace dioptre {
namespace math {

glm::float32 radToDeg(glm::float32 radians) {
  auto radianToDegreesFactor = 180 / M_PI;
  return radians * radianToDegreesFactor;
}

glm::float32 degToRad(glm::float32 degrees) {
  auto degreeToRadiansFactor = M_PI / 180;
  return degrees * degreeToRadiansFactor;
}

}
}

#endif // DIOPTRE_MATH_CONVERSION_H_
