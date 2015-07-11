#ifndef DIOPTRE_TIME_NULL_TIME_H_
#define DIOPTRE_TIME_NULL_TIME_H_

#include "dioptre/time/time_interface.h"

namespace dioptre {
namespace time {
namespace null {

class Time : public dioptre::time::TimeInterface {
public:
  int initialize() { return 0; }
  void destroy() { }

  double getTime() { return 1337; }
}; // Time

} // null
} // time
} // dioptre

#endif // DIOPTRE_TIME_NULL_TIME_H_
