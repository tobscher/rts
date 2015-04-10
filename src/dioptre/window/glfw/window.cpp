#include <iostream>
#include <GLFW/glfw3.h>

#include "dioptre/window/glfw/window.h"

namespace dioptre {
namespace window {
namespace glfw {

Window::Window()
  : glfwWindow_(nullptr) {
}

int Window::initialize() {
  // Initialise GLFW
  if(!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

  // Open a window and create its OpenGL context
  /* glfwSetErrorCallback(error_callback); */
  glfwWindow_ = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
  if (glfwWindow_ == NULL) {
    fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(glfwWindow_);

  return 0;
}

void Window::destroy() {
  glfwDestroyWindow(glfwWindow_);
  glfwTerminate();
}

int Window::shouldClose() {
  return glfwWindowShouldClose(glfwWindow_);
}

void Window::setShouldClose(bool value) {
  glfwSetWindowShouldClose(glfwWindow_, value);
}

void Window::swapBuffers() {
  glfwSwapBuffers(glfwWindow_);
  glfwPollEvents();
}

GLFWwindow* Window::GetWindow() {
  return glfwWindow_;
}

} // glfw
} // window
} // dioptre
