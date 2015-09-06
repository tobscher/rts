#ifndef RTS_SELECTOR_H_
#define RTS_SELECTOR_H_

#include "dioptre/object.h"
#include "dioptre/graphics/component.h"

namespace rts {

class Selector {
public:
  Selector(dioptre::Object* object);

  void select();
  void setTarget(dioptre::Object* target, float size);

private:
  dioptre::Object* object_;
}; // Selector

} // rts

#endif // RTS_SELECTOR_H_
