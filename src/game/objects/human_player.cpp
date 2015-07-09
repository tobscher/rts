#include "human_player.h"
#include "components/edge_scroll_component.h"

namespace objects {

HumanPlayer* HumanPlayer::spawn() {
  HumanPlayer* humanPlayer = new HumanPlayer();

  auto edgeScrollComponent = new components::EdgeScrollComponent();
  humanPlayer->addComponent(edgeScrollComponent);

  return humanPlayer;
}

} // objects
