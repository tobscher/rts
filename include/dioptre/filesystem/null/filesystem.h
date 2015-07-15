#ifndef DIOPTRE_FILESYSTEM_NULL_FILESYSTEM_H_
#define DIOPTRE_FILESYSTEM_NULL_FILESYSTEM_H_

#include <string>

#include "dioptre/filesystem/filesystem_interface.h"

namespace dioptre {
namespace filesystem {
namespace null {

class Filesystem : public dioptre::filesystem::FilesystemInterface {
public:
  virtual ~Filesystem();

  // Module
  int initialize() { return 0; }
  void destroy() { }

  void registerFromArgs(char *argv[]) { }
  void registerPath(std::string path) { }
  void clear() { }
  std::string find(std::string file) { return file; }
  int read(std::string file, void* buffer, int size) { return size; }
  int size(std::string file) { return 0; }
  std::string readAll(std::string file) { return file; };
}; // Filesystem

} // null
} // filesystem
} // dioptre

#endif // DIOPTRE_FILESYSTEM_NULL_FILESYSTEM_H_
