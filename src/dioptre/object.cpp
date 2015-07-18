#include "dioptre/object.h"

namespace dioptre {

Object::Object(std::string name) :
  transform_(new Transform()),
  name_(name) {
  logger_ = log4cxx::Logger::getLogger(name);
}

Object::~Object() {
  for (auto c : components_) {
    delete c;
  }
}

void Object::addComponent(ComponentInterface* component) {
  component->setObject(this);
  components_.push_back(component);
}

void Object::update() {
  for (auto c : components_) {
    c->update();
  }
}

// TODO(Tobscher): Implement this method.
template <typename T>
T* Object::getComponent() {
  return nullptr;
}

}
