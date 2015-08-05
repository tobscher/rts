#ifndef RTS_UNIT_H_
#define RTS_UNIT_H_

#include "dioptre/object.h"
#include "rts/map.h"

namespace rts {

class Unit : public dioptre::Object {
public:
  Unit() : Object("objects.unit") {}
  void handleClick(glm::vec3 hitPoint);

  static Unit* spawn(Map* map);
}; // Unit

} // rts

#endif // RTS_UNIT_H_
