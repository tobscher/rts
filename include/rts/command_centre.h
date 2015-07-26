#ifndef RTS_COMMAND_CENTRE_H_
#define RTS_COMMAND_CENTRE_H_

#include "dioptre/object.h"
#include "rts/map.h"

namespace rts {

class CommandCentre : public dioptre::Object {
public:
  CommandCentre() : Object("objects.command_centre") {}
  void handleClick(glm::vec3 hitPoint);

  static CommandCentre* spawn(Map* map);
};

} // rts

#endif // RTS_COMMAND_CENTRE_H_
