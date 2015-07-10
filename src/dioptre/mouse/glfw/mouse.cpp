#include "dioptre/locator.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/mouse/glfw/mouse.h"

namespace dioptre {
namespace mouse {
namespace glfw {

int Mouse::initialize() {
  auto window = dioptre::Locator::getInstance<dioptre::window::glfw::Window>(dioptre::Module::M_WINDOW);
  GLFWwindow* glfwWindow = window->GetWindow();

  glfwSetCursorPosCallback(glfwWindow, cursorPosCallback);

  return 0;
}

void Mouse::destroy() {

}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
  auto mouse = dioptre::Locator::getInstance<dioptre::mouse::glfw::Mouse>(dioptre::Module::M_MOUSE);
  mouse->setPosition(xpos, ypos);
}

} // glfw
} // mouse
} // dioptre
