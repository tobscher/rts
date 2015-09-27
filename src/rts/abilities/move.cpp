#include "dioptre/application.h"

#include "rts/abilities/move.h"
#include "rts/game_object.h"
#include "rts/map.h"

#include <algorithm>

namespace rts {
namespace abilities {

Move::Move(rts::GameObject *gameObject)
    : rts::Ability("abilities.move", gameObject), speed_(1.0), moving_(false) {}

int Move::initialize() { return 0; }

void Move::update() {
  if (!moving_)
    return;

  auto from = gameObject_->getTransform()->getPosition();
  auto application = dioptre::Application::getInstance();
  auto map = application->getObject<rts::Map>();
  auto to = map->findPath(from, to_);
  auto distance = to - from;
  auto normalized = glm::normalize(distance);

  auto velocity = speed_ * 0.1;

  glm::float32 stepX = normalized.x * velocity;
  glm::float32 stepY = normalized.y * velocity;
  glm::float32 stepZ = normalized.z * velocity;

  auto endX = stepX < 0 ? std::max(from.x + stepX, to.x)
                        : std::min(from.x + stepX, to.x);
  auto endY = stepY < 0 ? std::max(from.y + stepY, to.y)
                        : std::min(from.y + stepY, to.y);
  auto endZ = stepZ < 0 ? std::max(from.z + stepZ, to.z)
                        : std::min(from.z + stepZ, to.z);

  gameObject_->getTransform()->setPosition(endX, endY, endZ);

  if (gameObject_->getTransform()->getPosition() == to_) {
    moving_ = false;
  }
}

void Move::destroy() {}

void Move::move(glm::vec3 to) {
  to_ = to;
  moving_ = true;
}

} // abilities
} // rts
