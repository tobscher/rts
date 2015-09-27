#include "rts/game_object.h"

namespace rts {

GameObject::GameObject(std::string name) : dioptre::Object(name) {}

GameObject::~GameObject() {
  for (auto it = abilities_.begin(); it != abilities_.end(); it++) {
    delete it->second;
  }
}

bool GameObject::hasAbility(rts::AbilityType type) {
  std::map<rts::AbilityType, rts::Ability *>::iterator it =
      abilities_.find(type);

  return it != abilities_.end();
}

rts::Ability *GameObject::getAbility(rts::AbilityType type) {
  std::map<rts::AbilityType, rts::Ability *>::iterator it =
      abilities_.find(type);

  if (it == abilities_.end()) {
    return nullptr;
  }

  return it->second;
}

void GameObject::addAbility(rts::AbilityType type, rts::Ability *ability) {
  abilities_.insert(std::pair<rts::AbilityType, rts::Ability *>(type, ability));
}

void GameObject::update() {
  dioptre::Object::update();

  for (auto it = abilities_.begin(); it != abilities_.end(); it++) {
    (*it).second->update();
  }
}

} // rts
