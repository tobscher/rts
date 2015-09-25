#include "rts/ability.h"

namespace rts {

Ability::Ability(std::string name, rts::GameObject *gameObject)
    : name_(name), gameObject_(gameObject) {}

} // rts
