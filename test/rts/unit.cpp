#include <gtest/gtest.h>

#include "rts/unit.h"

TEST(Unit, Abilities) {
  rts::Unit u;

  EXPECT_EQ(u.hasAbility(rts::A_MOVE), true);
}
