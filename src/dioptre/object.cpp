#include "dioptre/object.h"

namespace dioptre {

void Object::addComponent(ComponentInterface* component) {
  components_.push_back(component);
}

void Object::update() {
  for (auto c : components_) {
    c->update();
  }
}

}
