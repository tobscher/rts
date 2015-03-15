#include <unittest++/UnitTest++.h>
#include "dioptre/filesystem/path_lookup.h"

TEST(lookup_path_register_from_args) {
  char path[] = {"/usr/local/bin/game"};
  char *argv[] = {path};

  auto lookup = dioptre::filesystem::PathLookup::instance();
  lookup.clear();

  lookup.registerFromArgs(argv);

  CHECK_EQUAL(lookup.find("foo.frag"), "/usr/local/bin/foo.frag");
}

TEST(lookup_path_nothing_registered) {
  auto lookup = dioptre::filesystem::PathLookup::instance();
  lookup.clear();

  CHECK_EQUAL(lookup.find("foo.frag"), "foo.frag");
}
