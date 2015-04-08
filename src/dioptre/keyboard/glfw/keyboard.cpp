#include <iostream>
#include "dioptre/locator.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/keyboard/glfw/keyboard.h"

namespace dioptre {
namespace keyboard {
namespace glfw {

int Keyboard::initialize() {
  auto window = dioptre::Locator::getInstance<dioptre::window::glfw::Window>(dioptre::Module::M_WINDOW);
  GLFWwindow* glfwWindow = window->GetWindow();

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(glfwWindow, GLFW_STICKY_KEYS, GL_TRUE);
  glfwSetKeyCallback(glfwWindow, keyCallback);

  return 0;
}

void Keyboard::destroy() {

}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  // Use notification system
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    auto window = dioptre::Locator::getInstance<dioptre::window::glfw::Window>(dioptre::Module::M_WINDOW);
    auto glfwWindow = window->GetWindow();

    glfwSetWindowShouldClose(glfwWindow, GL_TRUE);
  }
}

}
}
}
