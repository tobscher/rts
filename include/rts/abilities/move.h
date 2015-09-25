#ifndef RTS_ABILITIES_MOVE_H_
#define RTS_ABILITIES_MOVE_H_

#include "rts/ability.h"

namespace rts {
namespace abilities {

class Move : public rts::Ability {
public:
  Move(rts::GameObject *gameObject);

  int initialize();
  void update();
  void destroy();
}; // Move

} // abilities
} // rts

#endif // RTS_ABILITIES_MOVE_H_
