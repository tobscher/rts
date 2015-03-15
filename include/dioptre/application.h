#ifndef DIOPTRE_APPLICATION_H_
#define DIOPTRE_APPLICATION_H_

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
}; // Application

} // dioptre

#endif // DIOPTRE_APPLICATION_H_
