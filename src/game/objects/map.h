#include "dioptre/object.h"

namespace objects {

class Map : public dioptre::Object {
public:
    static Map* spawn();
};

} // objects
