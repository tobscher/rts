#include "rts/game_object.h"

namespace rts {

GameObject::GameObject(std::string name) : dioptre::Object(name) {}

bool GameObject::hasAbility(rts::AbilityType type) {
  std::map<rts::AbilityType, rts::Ability *>::iterator it =
      abilities_.find(type);

  return it != abilities_.end();
}

GameObject::~GameObject() {
  for (auto it = abilities_.begin(); it != abilities_.end(); it++) {
    delete it->second;
  }
}

void GameObject::addAbility(rts::AbilityType type, rts::Ability *ability) {
  abilities_.insert(std::pair<rts::AbilityType, rts::Ability *>(type, ability));
}

} // rts
