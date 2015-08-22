#include "dioptre/filesystem/physfs/filesystem.h"
#include "physfs.h"
#include "dioptre/debug.h"

#include <exception>
#include <stdexcept>

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

int Filesystem::getSize(std::string file) {
  auto fileHandle = PHYSFS_openRead(file.c_str());
  if (!fileHandle) {
    return 0;
  }
  int size = PHYSFS_fileLength(fileHandle);
  PHYSFS_close(fileHandle);

  return size;
}

int Filesystem::read(std::string file, void* buffer, int size) {
  auto fileHandle = PHYSFS_openRead(file.c_str());
  if (!fileHandle) {
    return 0;
  }

  auto read = PHYSFS_read(fileHandle, buffer, 1, size);
  PHYSFS_close(fileHandle);

  if (read == -1) {
    std::string error(PHYSFS_getLastError());
    throw std::runtime_error(error);
  }

  return read;
}

std::string Filesystem::readAll(std::string file) {
  auto fileSize = getSize(file);
  char* buffer = new char[fileSize];
  auto length = read(file, buffer, fileSize);

  std::string s(buffer, length);

  delete buffer;

  return s;
}

} // physfs
} // filesystem
} // dioptre
