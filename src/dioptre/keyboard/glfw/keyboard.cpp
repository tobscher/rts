#include <iostream>
#include "dioptre/locator.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/keyboard/glfw/keyboard.h"

namespace dioptre {
namespace keyboard {
namespace glfw {

std::map<int, dioptre::keyboard::Key> Keyboard::keyMap_;

int Keyboard::initialize() {
  auto window = dioptre::Locator::getInstance<dioptre::window::glfw::Window>(dioptre::Module::M_WINDOW);
  GLFWwindow* glfwWindow = window->GetWindow();

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(glfwWindow, GLFW_STICKY_KEYS, GL_TRUE);
  glfwSetKeyCallback(glfwWindow, keyCallback);

  Keyboard::keyMap_[GLFW_KEY_ESCAPE] = dioptre::keyboard::KEY_ESCAPE;

  return 0;
}

void Keyboard::destroy() {

}

dioptre::keyboard::Key Keyboard::map(int key) {
  return Keyboard::keyMap_[key];
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  auto keyboard = dioptre::Locator::getInstance<dioptre::keyboard::glfw::Keyboard>(dioptre::Module::M_KEYBOARD);
  auto mappedKey = keyboard->map(key);

  if (action == GLFW_PRESS) {
    keyboard->press(mappedKey);
  }
}

} // glfw
} // keyboard
} // dioptre
