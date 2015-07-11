#include <iostream>
#include <exception>
#include <stdexcept>

#include "dioptre/application.h"
#include "dioptre/locator.h"
#include "dioptre/graphics/graphics_interface.h"
#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/window/window_interface.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/keyboard/keyboard_interface.h"
#include "dioptre/keyboard/glfw/keyboard.h"
#include "dioptre/filesystem/filesystem_interface.h"
#include "dioptre/filesystem/physfs/filesystem.h"

#include "keyboard/handlers/exit_game.h"

#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>

namespace dioptre {

Application::Application(int argc, char *argv[]) :
  windowService_(new dioptre::window::glfw::Window()),
  graphicsService_(new dioptre::graphics::opengl::Graphics()),
  keyboardService_(new dioptre::keyboard::glfw::Keyboard()),
  filesystemService_(new dioptre::filesystem::physfs::Filesystem()),
  mouseService_(new dioptre::mouse::glfw::Mouse()),
  timeService_(new dioptre::time::glfw::Time())
{
  // Enforce singleton property
  if (instance_) {
    throw std::runtime_error("Only one instance of Application allowed.");
  }

  instance_ = this;

  // Register current path of executable as lookup path
  filesystemService_->registerFromArgs(argv);
}

bool Application::isRunning() {
  return isRunning_;
}

int Application::initialize() {
  // Initialize services
  dioptre::Locator::initialize();
  dioptre::Locator::provide(Module::M_WINDOW, windowService_.get());
  dioptre::Locator::provide(Module::M_GRAPHICS, graphicsService_.get());
  dioptre::Locator::provide(Module::M_KEYBOARD, keyboardService_.get());
  dioptre::Locator::provide(Module::M_FILESYSTEM, filesystemService_.get());
  dioptre::Locator::provide(Module::M_MOUSE, mouseService_.get());
  dioptre::Locator::provide(Module::M_TIME, timeService_.get());

  windowService_->initialize();
  graphicsService_->initialize();
  keyboardService_->initialize();
  filesystemService_->initialize();
  mouseService_->initialize();
  timeService_->initialize();

  // Configure the logging mechanism
  log4cxx::LoggerPtr rootlogger = log4cxx::Logger::getRootLogger();
  rootlogger->addAppender(new log4cxx::ConsoleAppender(new log4cxx::PatternLayout("%d [%-5p] %c - %m%n")));

  return 0;
}

void Application::run() {
  isRunning_ = true;

  // free this handler
  dioptre::keyboard::handlers::ExitGame* exitGameHandler = new dioptre::keyboard::handlers::ExitGame();
  keyboardService_->registerKeyHandler(exitGameHandler);

  double lastTime = timeService_->getTime();
  int nbFrames = 0;

  while (!windowService_->shouldClose()) {
    // Measure speed
    double currentTime = timeService_->getTime();
    nbFrames++;
    if (currentTime - lastTime >= 1.0) {
      printf("%f ms/frame\n", 1000.0/double(nbFrames));
      nbFrames = 0;
      lastTime += 1.0;
    }

    for (auto o : objects_) {
      o->update();
    }

    graphicsService_->update();
    windowService_->swapBuffers();
  }

  keyboardService_->destroy();
  graphicsService_->destroy();
  windowService_->destroy();
  filesystemService_->destroy();
  mouseService_->destroy();
  timeService_->destroy();

  isRunning_ = false;
}

void Application::addObject(dioptre::Object* object) {
  objects_.push_back(object);
}

Application* Application::instance_ = 0;

log4cxx::LoggerPtr Application::logger_ = log4cxx::Logger::getLogger("dioptre");

} // dioptre
