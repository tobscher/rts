#ifndef RTS_UNIT_H_
#define RTS_UNIT_H_

#include "rts/game_object.h"
#include "rts/map.h"
#include "rts/selector.h"

#include <memory>

namespace rts {

class Unit : public rts::GameObject {
public:
  Unit();
  void handleClick(glm::vec3 hitPoint);

  Selector *getSelector();

  static Unit *spawn(Map *map);

private:
  std::unique_ptr<Selector> selector_;
}; // Unit

} // rts

#endif // RTS_UNIT_H_
