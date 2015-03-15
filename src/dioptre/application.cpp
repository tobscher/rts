#include <iostream>

#include "dioptre/filesystem/path_lookup.h"
#include "dioptre/application.h"
#include "dioptre/graphics/opengl/renderer.h"
#include "dioptre/window/glfw/window.h"

namespace dioptre {

Application::Application(int argc, char *argv[]) {
  dioptre::filesystem::PathLookup::instance().registerFromArgs(argv);
}

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
