#ifndef RTS_SELECTOR_H_
#define RTS_SELECTOR_H_

#include "rts/game_object.h"
#include "dioptre/graphics/component.h"

namespace rts {

class Selector {
public:
  explicit Selector(rts::GameObject *object);

  void select();
  void setTarget(rts::GameObject *target, float size);

private:
  rts::GameObject *object_;
}; // Selector

} // rts

#endif // RTS_SELECTOR_H_
