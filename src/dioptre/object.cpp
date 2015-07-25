#include "dioptre/object.h"

namespace dioptre {

Object::Object(std::string name) :
  state_(new State<Transform>()),
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

Transform* Object::getTransform() {
  return state_->getCurrent();
}

void Object::makeCurrent() {
  return state_->makeCurrent();
}

std::string Object::getName() {
  return name_;
}

void Object::handleClick(glm::vec3 hitPoint) {
  LOG4CXX_DEBUG(logger_, getName() << "; X:" << hitPoint.x << ", Y:" << hitPoint.y << "; Z:" << hitPoint.z);
}

}
