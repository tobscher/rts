#ifndef DIOPTRE_APPLICATION_H_
#define DIOPTRE_APPLICATION_H_

#include <memory>
#include <vector>

#include "spdlog/spdlog.h"

#include "object.h"
#include "graphics/graphics_interface.h"
#include "window/window_interface.h"
#include "keyboard/keyboard_interface.h"
#include "filesystem/filesystem_interface.h"
#include "mouse/mouse_interface.h"
#include "time/time_interface.h"
#include "physics/physics_interface.h"

namespace dioptre {

/**
 * 3D Application.
 */
class Application {
public:
  Application(int argc, char *argv[]);
  Application(int argc, char *argv[],
      dioptre::window::WindowInterface* windowService,
      dioptre::graphics::GraphicsInterface* graphicsService,
      dioptre::keyboard::KeyboardInterface* keyboardService,
      dioptre::filesystem::FilesystemInterface* filesystemService,
      dioptre::mouse::MouseInterface* mouseService,
      dioptre::time::TimeInterface* timeService,
      dioptre::physics::PhysicsInterface* physicsService
  );

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
   * Returns the status whether the application has been initialized.
   */
  bool getIsInitialized();

  /**
   * Runs the game loop.
   */
  void run();

  /**
   * Adds an object to the application.
   */
  void addObject(dioptre::Object* object);

  template <typename T>
  T* getObject() {
    for (auto object : objects_) {
      if (dynamic_cast<T*>(object) != nullptr) {
        return (T*)object;
      }
    }

    return nullptr;
  }

  static Application* getInstance();

private:
  bool isRunning_;
  bool isInitialized_;

  std::unique_ptr<dioptre::window::WindowInterface> windowService_;
  std::unique_ptr<dioptre::graphics::GraphicsInterface> graphicsService_;
  std::unique_ptr<dioptre::keyboard::KeyboardInterface> keyboardService_;
  std::unique_ptr<dioptre::filesystem::FilesystemInterface> filesystemService_;
  std::unique_ptr<dioptre::mouse::MouseInterface> mouseService_;
  std::unique_ptr<dioptre::time::TimeInterface> timeService_;
  std::unique_ptr<dioptre::physics::PhysicsInterface> physicsService_;

  std::vector<dioptre::Object*> objects_;

  static Application* instance_;
  static std::shared_ptr<spdlog::logger> logger_;
}; // Application

} // dioptre

#endif // DIOPTRE_APPLICATION_H_
