#include <exception>
#include <stdexcept>

#include "dioptre/application.h"
#include "dioptre/locator.h"
#include "dioptre/graphics/perspective_camera.h"
#include "dioptre/graphics/orthographic_camera.h"

#include "keyboard/handlers/exit_game.h"

namespace dioptre {

Application::Application(int argc, char *argv[])
    : Application(argc, argv, new dioptre::window::null::Window(),
                  new dioptre::graphics::null::Graphics(),
                  new dioptre::keyboard::null::Keyboard(),
                  new dioptre::filesystem::null::Filesystem(),
                  new dioptre::mouse::null::Mouse(),
                  new dioptre::time::null::Time(),
                  new dioptre::physics::null::Physics()) {}

Application::Application(
    int argc, char *argv[], dioptre::window::WindowInterface *windowService,
    dioptre::graphics::GraphicsInterface *graphicsService,
    dioptre::keyboard::KeyboardInterface *keyboardService,
    dioptre::filesystem::FilesystemInterface *filesystemService,
    dioptre::mouse::MouseInterface *mouseService,
    dioptre::time::TimeInterface *timeService,
    dioptre::physics::PhysicsInterface *physicsService)
    : isRunning_(false), isInitialized_(false), windowService_(windowService),
      graphicsService_(graphicsService), keyboardService_(keyboardService),
      filesystemService_(filesystemService), mouseService_(mouseService),
      timeService_(timeService), physicsService_(physicsService) {
  // Enforce singleton property
  if (instance_) {
    throw std::runtime_error("Only one instance of Application allowed.");
  }

  instance_ = this;

  // Register current path of executable as lookup path
  filesystemService_->registerFromArgs(argv);
}

Application::~Application() {
  logger_->info("Cleaning up objects");
  for (auto o : objects_) {
    delete o;
  }

  instance_ = nullptr;
}

bool Application::isRunning() { return isRunning_; }

int Application::initialize() {
  if (isInitialized_)
    return 0;

  logger_->set_level(spdlog::level::debug);

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

  auto windowSize = windowService_->getSize();

  // Add main layer
  auto camera = new dioptre::graphics::PerspectiveCamera(
      28.0,                                 // field of view
      windowSize.width / windowSize.height, // aspect ratio
      1.0,                                  // near
      1000.0                                // far
      );
  auto transform = camera->getTransform();

  transform->setPosition(0, 38, 5);
  transform->lookAt(0.0f, 0.0f, 0.0f);

  auto scene = new dioptre::graphics::Scene();
  auto mainLayer = new dioptre::graphics::Layer(scene, camera);
  graphicsService_->addLayer(mainLayer);

  // Add HUD layer
  auto hudCamera = new dioptre::graphics::OrthographicCamera(
      0.0f, (float)windowSize.width, (float)windowSize.height, 0.0f, -1000.0,
      1000.0);
  auto hudScene = new dioptre::graphics::Scene();
  auto hudLayer = new dioptre::graphics::Layer(hudScene, hudCamera);
  graphicsService_->addLayer(hudLayer);

  for (auto object : objects_) {
    object->initialize();
  }

  isInitialized_ = true;

  return 0;
}

bool Application::getIsInitialized() { return isInitialized_; }

void Application::run() {
  isRunning_ = true;

  // free this handler
  dioptre::keyboard::handlers::ExitGame *exitGameHandler =
      new dioptre::keyboard::handlers::ExitGame();
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
    if (currentTime - lastTime >= 1.0) {
      logger_->debug("{} ms/frame", 1000.0 / double(nbFrames));
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
      physicsService_->simulate();
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

void Application::addObject(dioptre::Object *object) {
  objects_.push_back(object);
}

Application *Application::getInstance() { return instance_; }

Application *Application::instance_ = nullptr;

std::shared_ptr<spdlog::logger> Application::logger_ =
    spdlog::stdout_logger_mt("dioptre");

} // dioptre
