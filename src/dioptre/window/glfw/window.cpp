#include <GLFW/glfw3.h>

#include "dioptre/window/glfw/window.h"

namespace dioptre {
namespace window {
namespace glfw {

Window::Window()
  : glfwWindow_(nullptr) {
}

// TODO(Tobscher) initialize window from settings, e.g. only go into fullscreen if requested.
int Window::initialize() {
  // Initialise GLFW
  if(!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  glfwMonitor_ = glfwGetPrimaryMonitor();
  glfwVideoMode_ = glfwGetVideoMode(glfwMonitor_);

  glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
  glfwWindowHint(GLFW_RED_BITS, glfwVideoMode_->redBits);
  glfwWindowHint(GLFW_GREEN_BITS, glfwVideoMode_->greenBits);
  glfwWindowHint(GLFW_BLUE_BITS, glfwVideoMode_->blueBits);
  glfwWindowHint(GLFW_REFRESH_RATE, glfwVideoMode_->refreshRate);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

  // Open a window and create its OpenGL context
  /* glfwWindow_ = glfwCreateWindow(glfwVideoMode_->width, glfwVideoMode_->height, "RTS", nullptr, nullptr); */
  glfwWindow_ = glfwCreateWindow(glfwVideoMode_->width, glfwVideoMode_->height, "RTS", glfwMonitor_, nullptr);
  if (glfwWindow_ == NULL) {
    logger_->error("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.");
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

Size Window::getSize() {
  int width, height;
  glfwGetWindowSize(glfwWindow_, &width, &height);

  return Size(width, height);
}

} // glfw
} // window
} // dioptre
