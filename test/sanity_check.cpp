#include "gtest/gtest.h"
#include "matcher.h"

TEST(Main, SanityCheck)
{
  ASSERT_TRUE(true);
  ASSERT_EQ(2,1+1);

  int x[] = {1,2,3};
  int y[] = {1,2,3};
  ASSERT_TRUE(ArraysMatch(x,y));

  double a = 1.51;
  double b = 1.52;
  ASSERT_NEAR(a,b,0.1);
}
