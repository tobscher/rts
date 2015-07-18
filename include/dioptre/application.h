#ifndef DIOPTRE_APPLICATION_H_
#define DIOPTRE_APPLICATION_H_

#include <memory>
#include <vector>
#include <log4cxx/logger.h>

#include "object.h"
#include "graphics/opengl/graphics.h"
#include "window/glfw/window.h"
#include "keyboard/glfw/keyboard.h"
#include "filesystem/physfs/filesystem.h"
#include "mouse/glfw/mouse.h"
#include "time/glfw/time.h"
#include "physics/bullet/physics.h"

namespace dioptre {

/**
 * 3D Application.
 */
class Application {
public:
  Application(int argc, char *argv[]);
  ~Application();

  /**
   * Indicates if the application is running.
   */
  bool isRunning();

  /**
   * Initializes the application.
   */
  int initialize();

  /**
   * Runs the game loop.
   */
  void run();

  /**
   * Adds an object to the application.
   */
  void addObject(dioptre::Object* object);

private:
  bool isRunning_;

  std::unique_ptr<dioptre::window::glfw::Window> windowService_;
  std::unique_ptr<dioptre::graphics::opengl::Graphics> graphicsService_;
  std::unique_ptr<dioptre::keyboard::glfw::Keyboard> keyboardService_;
  std::unique_ptr<dioptre::filesystem::physfs::Filesystem> filesystemService_;
  std::unique_ptr<dioptre::mouse::glfw::Mouse> mouseService_;
  std::unique_ptr<dioptre::time::glfw::Time> timeService_;
  std::unique_ptr<dioptre::physics::bullet::Physics> physicsService_;

  std::vector<dioptre::Object*> objects_;

  static Application* instance_;
  static log4cxx::LoggerPtr logger_;
}; // Application

} // dioptre

#endif // DIOPTRE_APPLICATION_H_
