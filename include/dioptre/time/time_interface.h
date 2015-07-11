#ifndef DIOPTRE_TIME_TIME_INTERFACE_H_
#define DIOPTRE_TIME_TIME_INTERFACE_H_

#include "dioptre/module.h"

namespace dioptre {
namespace time {

class TimeInterface : public dioptre::Module {
public:
  virtual ~TimeInterface() {}

  virtual double getTime() = 0;
}; // TimeInterface

} // time
} // dioptre

#endif // DIOPTRE_TIME_TIME_INTERFACE_H_
