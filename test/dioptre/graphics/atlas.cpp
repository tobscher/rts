#include <gtest/gtest.h>

#include "dioptre/graphics/atlas.h"
#include "dioptre/locator.h"
#include "dioptre/filesystem/physfs/filesystem.h"

TEST(Atlas, Description) {
  char empty[1] = {0};
  char *argv[] = {empty, 0};

  auto filesystem = new dioptre::filesystem::physfs::Filesystem();

  dioptre::Locator::initialize();
  dioptre::Locator::provide(dioptre::Module::M_FILESYSTEM, filesystem);

  filesystem->initialize();
  filesystem->registerFromArgs(argv);

  dioptre::graphics::Atlas atlas("fixtures/fonts/open_sans_regular_14.PNG", "fixtures/fonts/open_sans_regular_14.xml");

  EXPECT_EQ(atlas.initialize(), 0);
  EXPECT_TRUE(atlas.getImage() != nullptr);
  EXPECT_TRUE(atlas.getDescription() != nullptr);
  EXPECT_EQ(atlas.getWidth(), 256);
  EXPECT_EQ(atlas.getHeight(), 128);
  EXPECT_EQ(atlas.getComponents(), 4);
  EXPECT_EQ(atlas.getFamily(), "Open Sans");
  EXPECT_EQ(atlas.getFontHeight(), 26);
  EXPECT_EQ(atlas.getStyle(), "Regular");
  EXPECT_EQ(atlas.getSize(), 14);

  EXPECT_EQ(atlas.getChar('!').placeX, 2);
  EXPECT_EQ(atlas.getChar('!').placeY, 2);
  EXPECT_EQ(atlas.getChar('!').placeW, 3);
  EXPECT_EQ(atlas.getChar('!').placeH, 14);

  EXPECT_EQ(atlas.getChar('!').width, 5);
  EXPECT_EQ(atlas.getChar('!').offsetX, 1);
  EXPECT_EQ(atlas.getChar('!').offsetY, 6);

  filesystem->destroy();

  delete filesystem;
}
