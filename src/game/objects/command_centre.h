#include "dioptre/object.h"

namespace objects {

class CommandCentre : public dioptre::Object {
public:
  CommandCentre() : Object("objects.command_centre") {}
  static CommandCentre* spawn();
};

} // objects
