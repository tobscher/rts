#include <gtest/gtest.h>

#include "dioptre/locator.h"
#include "rts/human_player.h"
#include "rts/unit.h"

using rts::HumanPlayer;
using rts::Unit;

TEST(HumanPlayer, Select) {
  dioptre::Locator::initialize();

  HumanPlayer* player = HumanPlayer::spawn();
  Unit* unit = Unit::spawn();

  player->select(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 1);

  player->select(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 1);

  delete unit;
  delete player;
}
