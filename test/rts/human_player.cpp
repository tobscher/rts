#include <gtest/gtest.h>

#include "dioptre/locator.h"
#include "rts/map.h"
#include "rts/human_player.h"
#include "rts/unit.h"

using rts::Map;
using rts::HumanPlayer;
using rts::Unit;

TEST(HumanPlayer, Select) {
  dioptre::Locator::initialize();

  HumanPlayer* player = new HumanPlayer();
  Unit* unit = new Unit();

  player->select(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 1);

  player->select(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 1);

  delete unit;
  delete player;
}

TEST(HumanPlayer, Unselect) {
  dioptre::Locator::initialize();

  HumanPlayer* player = new HumanPlayer();
  Unit* unit = new Unit();

  player->select(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 1);

  player->unselect(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 0);

  player->unselect(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 0);

  delete unit;
  delete player;
}

TEST(HumanPlayer, ClearSelection) {
  dioptre::Locator::initialize();

  HumanPlayer* player = new HumanPlayer();
  Unit* unit = new Unit();

  player->select(unit);

  EXPECT_EQ(player->getSelectedObjects().size(), 1);

  player->clearSelection();

  EXPECT_EQ(player->getSelectedObjects().size(), 0);

  delete unit;
  delete player;
}
