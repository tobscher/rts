#include "dioptre/component_interface.h"
#include "dioptre/object.h"

namespace dioptre {
void ComponentInterface::setObject(Object* object) {
  object_ = object;
}

Object* ComponentInterface::getObject() {
  return object_;
}

}
