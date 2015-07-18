#include "dioptre/locator.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/mouse/glfw/mouse.h"

#include <iostream>

namespace dioptre {
namespace mouse {
namespace glfw {

int Mouse::initialize() {
  auto window = dioptre::Locator::getInstance<dioptre::window::glfw::Window>(dioptre::Module::M_WINDOW);
  GLFWwindow* glfwWindow = window->GetWindow();

  glfwSetCursorPosCallback(glfwWindow, cursorPosCallback);
  glfwSetMouseButtonCallback(glfwWindow, mouseCallback);

  return 0;
}

void Mouse::destroy() {

}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
  auto mouse = dioptre::Locator::getInstance<dioptre::mouse::MouseInterface>(dioptre::Module::M_MOUSE);
  mouse->setPosition(xpos, ypos);
}

void mouseCallback(GLFWwindow* window, int button, int action, int mods) {
  auto mouse = dioptre::Locator::getInstance<dioptre::mouse::MouseInterface>(dioptre::Module::M_MOUSE);
  auto physics = dioptre::Locator::getInstance<dioptre::physics::PhysicsInterface>(dioptre::Module::M_PHYSICS);
  physics->castRay(mouse->getPosition());
}

} // glfw
} // mouse
} // dioptre
