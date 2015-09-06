#ifndef RTS_COMMAND_CENTRE_H_
#define RTS_COMMAND_CENTRE_H_

#include "dioptre/object.h"
#include "rts/map.h"
#include "rts/selector.h"

#include <memory>

namespace rts {

class CommandCentre : public dioptre::Object {
public:
  CommandCentre();
  void handleClick(glm::vec3 hitPoint);

  Selector* getSelector();

  static CommandCentre* spawn(Map* map);

private:
  std::unique_ptr<Selector> selector_;
}; // CommandCentre

} // rts

#endif // RTS_COMMAND_CENTRE_H_
