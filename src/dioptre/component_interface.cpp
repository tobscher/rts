#include "dioptre/component_interface.h"
#include "dioptre/object.h"

namespace dioptre {

ComponentInterface::ComponentInterface(std::string name) :
  name_(name),
  isInitialized_(false) {
  logger_ = spdlog::get("dioptre");
}

void ComponentInterface::setObject(Object* object) {
  object_ = object;
}

Object* ComponentInterface::getObject() {
  return object_;
}

int ComponentInterface::initialize() {
  if (isInitialized_) return 0;

  isInitialized_ = true;

  return 0;
}

bool ComponentInterface::getIsInitialized() {
  return isInitialized_;
}

}
