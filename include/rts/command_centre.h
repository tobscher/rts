#ifndef RTS_COMMAND_CENTRE_H_
#define RTS_COMMAND_CENTRE_H_

#include "dioptre/object.h"

namespace rts {

class CommandCentre : public dioptre::Object {
public:
  CommandCentre() : Object("objects.command_centre") {}
  static CommandCentre* spawn();
};

} // rts

#endif // RTS_COMMAND_CENTRE_H_
