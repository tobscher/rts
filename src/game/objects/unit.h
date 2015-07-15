#include "dioptre/object.h"

namespace objects {

class Unit : public dioptre::Object {
public:
  Unit() : Object("objects.unit") {}
  static Unit* spawn();
};

} // objects
