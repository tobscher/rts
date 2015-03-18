#include <iostream>
#include <exception>

#include "dioptre/filesystem/path_lookup.h"
#include "dioptre/application.h"
#include "dioptre/graphics/opengl/renderer.h"
#include "dioptre/window/glfw/window.h"

#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>

namespace dioptre {

Application::Application(int argc, char *argv[]) {
  // Enforce singleton property
  if (instance_) {
      throw std::runtime_error("Only one instance of Application allowed.");
  }

  instance_ = this;

  // Register current path of executable as shader lookup path
  dioptre::filesystem::PathLookup::instance().registerFromArgs(argv);

  // Configure the logging mechanism
  log4cxx::LoggerPtr rootlogger = log4cxx::Logger::getRootLogger();
  rootlogger->addAppender(new log4cxx::ConsoleAppender(new log4cxx::PatternLayout("%d [%-5p] %c - %m%n")));
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

Application* Application::instance_ = 0;

log4cxx::LoggerPtr Application::logger_ = log4cxx::Logger::getLogger("dioptre");

}
