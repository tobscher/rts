#include "dioptre/object.h"

namespace dioptre {

Object::Object(std::string name)
    : state_(new State<Transform>()), name_(name), isInitialized_(false) {
  logger_ = spdlog::get("dioptre");
}

Object::~Object() {
  for (auto c : components_) {
    delete c;
  }
}

void Object::addComponent(ComponentInterface *component) {
  component->setObject(this);
  components_.push_back(component);
}

int Object::initialize() {
  if (isInitialized_)
    return 0;

  for (auto component : components_) {
    component->initialize();
  }

  isInitialized_ = true;

  return 0;
}

void Object::update() {
  for (auto c : components_) {
    c->update();
  }
}

Transform *Object::getTransform() { return state_->getCurrent(); }

void Object::makeCurrent() { return state_->makeCurrent(); }

std::string Object::getName() { return name_; }

bool Object::getIsInitialized() { return isInitialized_; }

void Object::handleClick(glm::vec3 hitPoint) {
  logger_->debug(getName()) << "; X:" << hitPoint.x << ", Y:" << hitPoint.y
                            << "; Z:" << hitPoint.z;
}
}
