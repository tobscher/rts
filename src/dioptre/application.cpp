#include "dioptre/application.h"
#include "dioptre/graphics/opengl/renderer.h"
#include "dioptre/window/glfw/window.h"

namespace dioptre {

bool Application::isRunning() {
  return isRunning_;
}

void Application::run() {
  isRunning_ = true;

  dioptre::window::glfw::Window* window = new dioptre::window::glfw::Window();
  window->create();
  dioptre::graphics::opengl::Renderer renderer(window);
  renderer.Initialize();

  while(!window->shouldClose()) {
    renderer.Render();
    window->swapBuffers();
  }

  renderer.Destroy();
  window->destroy();

  isRunning_ = false;
}

}
