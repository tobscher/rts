#ifndef DIOPTRE_APPLICATION_H_
#define DIOPTRE_APPLICATION_H_

#include <log4cxx/logger.h>

namespace dioptre {

/**
 * 3D Application.
 */
class Application {
public:
  Application(int argc, char *argv[]);

  /**
   * Indicates if the application is running.
   */
  bool isRunning();

  /**
   * Runs the game loop.
   */
  void run();

private:
  bool isRunning_;
  static Application* instance_;
  static log4cxx::LoggerPtr logger_;
}; // Application

} // dioptre

#endif // DIOPTRE_APPLICATION_H_
