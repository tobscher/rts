#ifndef DIOPTRE_MODULE_H_
#define DIOPTRE_MODULE_H_

#include "log4cxx/logger.h"
#include <string>

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
    M_PHYSICS,
    M_MAX_ENUM
  };

  Module(std::string name);
  virtual ~Module() {}

  virtual int initialize() = 0;
  virtual void destroy() = 0;

protected:
  std::string name_;
  log4cxx::LoggerPtr logger_;
};

}

#endif
