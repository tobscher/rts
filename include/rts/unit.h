#ifndef RTS_UNIT_H_
#define RTS_UNIT_H_

#include "dioptre/object.h"

namespace rts {

class Unit : public dioptre::Object {
public:
  Unit() : Object("objects.unit") {}

  static Unit* spawn();
};

} // rts

#endif // RTS_UNIT_H_
