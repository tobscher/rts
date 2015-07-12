#include "dioptre/filesystem/physfs/filesystem.h"
#include "physfs.h"
#include "dioptre/debug.h"

#include <iostream>

namespace dioptre {
namespace filesystem {
namespace physfs {

void Filesystem::destroy() {
  PHYSFS_deinit();
};

void Filesystem::registerFromArgs(char *argv[]) {
  PHYSFS_init(argv[0]);

  std::string baseDir(PHYSFS_getBaseDir());
  registerPath(baseDir.c_str());

  // Files are located in the resources directory
#ifdef __APPLE__
  registerPath(baseDir.append("Contents/Resources/"));
#endif
}

void Filesystem::registerPath(std::string path) {
  PHYSFS_addToSearchPath(path.c_str(), 1);
}

void Filesystem::clear() {
  destroy();
}

std::string Filesystem::find(std::string file) {
  std::string fileDir(PHYSFS_getRealDir(file.c_str()));
  return fileDir.append(file);
}

} // physfs
} // filesystem
} // dioptre
