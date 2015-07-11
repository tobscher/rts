#include "dioptre/time/glfw/time.h"
#include "GLFW/glfw3.h"

namespace dioptre {
namespace time {
namespace glfw {

int Time::initialize() {
  return 0;
}

void Time::destroy() {
}

double Time::getTime() {
  return glfwGetTime();
}

} // glfw
} // time
} // dioptre
