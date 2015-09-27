#ifndef RTS_ABILITIES_MOVE_H_
#define RTS_ABILITIES_MOVE_H_

#include "rts/ability.h"
#include "glm/glm.hpp"

namespace rts {
namespace abilities {

class Move : public rts::Ability {
public:
  Move(rts::GameObject *gameObject);

  int initialize();
  void update();
  void destroy();

  void move(glm::vec3 to);

private:
  glm::float32 speed_;

  bool moving_;
  glm::vec3 to_;
}; // Move

} // abilities
} // rts

#endif // RTS_ABILITIES_MOVE_H_
