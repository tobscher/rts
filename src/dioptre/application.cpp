#include <iostream>

#include <boost/filesystem.hpp>

#include "dioptre/application.h"
#include "dioptre/graphics/opengl/renderer.h"
#include "dioptre/window/glfw/window.h"

namespace dioptre {

boost::filesystem::path g_lookupPath;

Application::Application(int argc, char *argv[]) {
  auto f = argv[0];
  auto absolute = boost::filesystem::absolute(f);

  g_lookupPath = absolute.remove_leaf();
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
