#ifndef RTS_TEXT_H_
#define RTS_TEXT_H_

#include "dioptre/object.h"

namespace rts {

class Text : public dioptre::Object {
public:
  Text() : Object("objects.text") {}
  static Text* spawn();
}; // Text

} // rts

#endif // RTS_TEXT_H_
