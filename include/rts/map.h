#ifndef RTS_MAP_H_
#define RTS_MAP_H_

#include "dioptre/object.h"

namespace rts {

const double cellSize = 1.0;

class Map : public dioptre::Object {
public:
  Map() : Object("objects.map") {}

  void handleClick(glm::vec3 hitPoint);

  static Map *spawn();
}; // Map

} // rts

#endif // RTS_MAP_H_
