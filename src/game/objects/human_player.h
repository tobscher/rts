#include "dioptre/object.h"

namespace objects {

class HumanPlayer : public dioptre::Object {
public:
  HumanPlayer() : Object("ojects.human_player") {}

  void makeCurrent();

  static HumanPlayer* spawn();
}; // HumanPlayer

} // objects
