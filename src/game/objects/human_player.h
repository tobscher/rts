#include "dioptre/object.h"

namespace objects {

class HumanPlayer : public dioptre::Object {
public:
  static HumanPlayer* spawn();
}; // HumanPlayer

} // objects
