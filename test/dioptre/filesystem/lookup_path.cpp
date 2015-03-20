#include <gtest/gtest.h>
#include "dioptre/filesystem/path_lookup.h"

TEST(LookupPath, RegisterFromArgs) {
  char path[] = {"/usr/local/bin/game"};
  char *argv[] = {path};

  auto lookup = dioptre::filesystem::PathLookup::instance();
  lookup.clear();

  lookup.registerFromArgs(argv);

  EXPECT_EQ(lookup.find("foo.frag"), "/usr/local/bin/foo.frag");
}

TEST(LookupPath, NothingRegistered) {
  auto lookup = dioptre::filesystem::PathLookup::instance();
  lookup.clear();

  EXPECT_EQ(lookup.find("foo.frag"), "foo.frag");
}
