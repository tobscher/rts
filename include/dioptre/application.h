#ifndef DIOPTRE_APPLICATION_H_
#define DIOPTRE_APPLICATION_H_

namespace dioptre {

class Application {
public:
  Application(int argc, char *argv[]);
  bool isRunning();
  void run();

private:
  bool isRunning_;
};

}

#endif // DIOPTRE_APPLICATION_H_
