#ifndef RTS_MAP_H_
#define RTS_MAP_H_

#include "dioptre/object.h"

namespace rts {

class Map : public dioptre::Object {
public:
  Map() : Object("objects.map") {}
  static Map* spawn();
};

} // rts

#endif // RTS_MAP_H_
