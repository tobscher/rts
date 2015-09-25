#include "rts/abilities/move.h"

namespace rts {
namespace abilities {

Move::Move(rts::GameObject *gameObject)
    : rts::Ability("abilities.move", gameObject) {}

int Move::initialize() { return 0; }

void Move::update() {}

void Move::destroy() {}

} // abilities
} // rts
