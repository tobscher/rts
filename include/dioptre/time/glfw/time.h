#ifndef DIOPTRE_TIME_GLFW_TIME_H_
#define DIOPTRE_TIME_GLFW_TIME_H_

#include "dioptre/time/time_interface.h"

namespace dioptre {
namespace time {
namespace glfw {

class Time : public dioptre::time::TimeInterface {
public:
  int initialize();
  void destroy();

  double getTime();
}; // Time

} // glfw
} // time
} // dioptre

#endif // DIOPTRE_TIME_GLFW_TIME_H_
