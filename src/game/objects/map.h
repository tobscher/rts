#include "dioptre/object.h"

namespace objects {

class Map : public dioptre::Object {
public:
  Map() : Object("objects.map") {}
  static Map* spawn();
};

} // objects
