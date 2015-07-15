#ifndef DIOPTRE_FILESYSTEM_PHYSFS_FILESYSTEM_H_
#define DIOPTRE_FILESYSTEM_PHYSFS_FILESYSTEM_H_

#include "dioptre/filesystem/filesystem_interface.h"

namespace dioptre {
namespace filesystem {
namespace physfs {

class Filesystem : public dioptre::filesystem::FilesystemInterface {
public:
  // Module
  int initialize() { return 0; }
  void destroy();

  void registerFromArgs(char *argv[]);
  void registerPath(std::string path);
  void clear();
  std::string find(std::string file);
  int read(std::string file, void* buffer, int size);
  int getSize(std::string file);
  std::string readAll(std::string file);
}; // Filesystem

} // physfs
} // filesystem
} // dioptre

#endif // DIOPTRE_FILESYSTEM_PHYSFS_FILESYSTEM_H_
