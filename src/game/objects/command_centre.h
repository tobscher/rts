#include "dioptre/object.h"

namespace objects {

class CommandCentre : public dioptre::Object {
public:
    static CommandCentre* spawn();
};

} // objects
