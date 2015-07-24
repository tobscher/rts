#include <iostream>
#include <exception>
#include <stdexcept>

#include "dioptre/application.h"
#include "dioptre/locator.h"

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
  timeService_(new dioptre::time::glfw::Time()),
  physicsService_(new dioptre::physics::bullet::Physics())
{
  // Enforce singleton property
  if (instance_) {
    throw std::runtime_error("Only one instance of Application allowed.");
  }

  instance_ = this;

  // Register current path of executable as lookup path
  filesystemService_->registerFromArgs(argv);
}

Application::~Application() {
  LOG4CXX_INFO(logger_, "Cleaning up objects");
  for (auto o : objects_) {
    delete o;
  }
}

bool Application::isRunning() {
  return isRunning_;
}

int Application::initialize() {
  // Configure the logging mechanism
  log4cxx::LoggerPtr rootlogger = log4cxx::Logger::getRootLogger();
  rootlogger->addAppender(new log4cxx::ConsoleAppender(new log4cxx::PatternLayout("%d [%-5p] %c - %m%n")));

  // Initialize services
  dioptre::Locator::initialize();
  dioptre::Locator::provide(Module::M_WINDOW, windowService_.get());
  dioptre::Locator::provide(Module::M_GRAPHICS, graphicsService_.get());
  dioptre::Locator::provide(Module::M_KEYBOARD, keyboardService_.get());
  dioptre::Locator::provide(Module::M_FILESYSTEM, filesystemService_.get());
  dioptre::Locator::provide(Module::M_MOUSE, mouseService_.get());
  dioptre::Locator::provide(Module::M_TIME, timeService_.get());
  dioptre::Locator::provide(Module::M_PHYSICS, physicsService_.get());

  windowService_->initialize();
  graphicsService_->initialize();
  keyboardService_->initialize();
  filesystemService_->initialize();
  mouseService_->initialize();
  timeService_->initialize();
  physicsService_->initialize();

  return 0;
}

void Application::run() {
  isRunning_ = true;

  // free this handler
  dioptre::keyboard::handlers::ExitGame* exitGameHandler = new dioptre::keyboard::handlers::ExitGame();
  keyboardService_->registerKeyHandler(exitGameHandler);

  graphicsService_->initializeScene();
  physicsService_->initializeWorld();

  double previousTime = timeService_->getTime();
  double lastTime = previousTime;
  double accumulator = 0.0;
  double dt = 0.01;
  int nbFrames = 0;

  while (!windowService_->shouldClose()) {
    double currentTime = timeService_->getTime();
    double elapsed = currentTime - previousTime;
    nbFrames++;

    // Frame counter
    if (currentTime - lastTime >= 1.0 ) {
      printf("%f ms/frame\n", 1000.0/double(nbFrames));
      nbFrames = 0;
      lastTime += 1.0;
    }

    if (elapsed > 0.25) {
      elapsed = 0.25;
    }

    previousTime = currentTime;
    accumulator += elapsed;

    while (accumulator >= dt) {
      for (auto o : objects_) {
        o->makeCurrent();
        o->update();
      }
      physicsService_->debug();
      accumulator -= dt;
    }

    const double alpha = accumulator / dt;

    graphicsService_->render(alpha);
    windowService_->swapBuffers();
  }

  keyboardService_->destroy();
  graphicsService_->destroy();
  windowService_->destroy();
  filesystemService_->destroy();
  mouseService_->destroy();
  timeService_->destroy();
  physicsService_->destroy();

  isRunning_ = false;
}

void Application::addObject(dioptre::Object* object) {
  objects_.push_back(object);
}

Application* Application::instance_ = 0;

log4cxx::LoggerPtr Application::logger_ = log4cxx::Logger::getLogger("dioptre");

} // dioptre
