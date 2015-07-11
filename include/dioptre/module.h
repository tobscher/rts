#ifndef DIOPTRE_MODULE_H_
#define DIOPTRE_MODULE_H_

namespace dioptre {

class Module {
public:
  enum ModuleType {
    M_WINDOW,
    M_GRAPHICS,
    M_KEYBOARD,
    M_FILESYSTEM,
    M_MOUSE,
    M_TIME,
    M_MAX_ENUM
  };

  virtual ~Module() {}

  virtual int initialize() = 0;
  virtual void destroy() = 0;
};

}

#endif
