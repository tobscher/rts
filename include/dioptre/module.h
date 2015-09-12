#ifndef DIOPTRE_MODULE_H_
#define DIOPTRE_MODULE_H_

#include "spdlog/spdlog.h"
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
    M_AI,
    M_MAX_ENUM
  };

  explicit Module(std::string name);
  virtual ~Module() {}

  virtual int initialize() = 0;
  virtual void destroy() = 0;

protected:
  std::string name_;
  std::shared_ptr<spdlog::logger> logger_;
};
}

#endif
