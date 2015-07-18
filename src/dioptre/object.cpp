#include "dioptre/object.h"

namespace dioptre {

Object::Object(std::string name) :
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

void Object::addComponent(dioptre::graphics::Component* component) {
  component->setObject(this);
  graphicsComponents_.push_back(component);
  components_.push_back(component);
}

void Object::addComponent(dioptre::physics::Component* component) {
  component->setObject(this);
  physicsComponents_.push_back(component);
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

template <>
dioptre::graphics::Component* Object::getComponent<dioptre::graphics::Component>() {
  if (graphicsComponents_.size() > 0) {
    return graphicsComponents_[0];
  }

  return nullptr;
}

}
