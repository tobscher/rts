#include <iostream>
#include <exception>
#include <stdexcept>

#include "dioptre/application.h"
#include "dioptre/locator.h"
#include "dioptre/filesystem/path_lookup.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/keyboard/keyboard_interface.h"
#include "dioptre/keyboard/glfw/keyboard.h"

#include "keyboard/handlers/exit_game.h"

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

  // Initialize services
  dioptre::Locator::initialize();
  dioptre::Locator::provide(Module::M_WINDOW, new dioptre::window::glfw::Window());
  dioptre::Locator::provide(Module::M_GRAPHICS, new dioptre::graphics::opengl::Graphics());
  dioptre::Locator::provide(Module::M_KEYBOARD, new dioptre::keyboard::glfw::Keyboard());

  // Configure the logging mechanism
  log4cxx::LoggerPtr rootlogger = log4cxx::Logger::getRootLogger();
  rootlogger->addAppender(new log4cxx::ConsoleAppender(new log4cxx::PatternLayout("%d [%-5p] %c - %m%n")));
}

bool Application::isRunning() {
  return isRunning_;
}

void Application::run() {
  isRunning_ = true;

  auto window = dioptre::Locator::getInstance<dioptre::window::WindowInterface>(dioptre::Module::M_WINDOW);
  auto graphics = dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto keyboard = dioptre::Locator::getInstance<dioptre::keyboard::KeyboardInterface>(dioptre::Module::M_KEYBOARD);

  window->initialize();
  graphics->initialize();
  keyboard->initialize();

  dioptre::keyboard::handlers::ExitGame* exitGameHandler = new dioptre::keyboard::handlers::ExitGame();
  keyboard->registerKeyHandler(exitGameHandler);

  while(!window->shouldClose()) {
    graphics->render();
    window->swapBuffers();
  }

  graphics->destroy();
  window->destroy();

  isRunning_ = false;
}

Application* Application::instance_ = 0;

log4cxx::LoggerPtr Application::logger_ = log4cxx::Logger::getLogger("dioptre");

}
