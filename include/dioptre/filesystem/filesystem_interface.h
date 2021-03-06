#ifndef DIOPTRE_FILESYSTEM_FILESYSTEM_INTERFACE_H_
#define DIOPTRE_FILESYSTEM_FILESYSTEM_INTERFACE_H_

#include <vector>
#include <string>

#include "dioptre/module.h"

namespace dioptre {
namespace filesystem {

/**
 * Class to lookup files from registered paths.
 * This class is a singleton.
 */
class FilesystemInterface : public Module {
public:
  FilesystemInterface() : Module("dioptre.filesystem") {}

  virtual ~FilesystemInterface() {}

  /*
   * Register path of the exectable as a registered
   * lookup path
   */
  virtual void registerFromArgs(char *argv[]) = 0;

  /*
   * Register given path as lookup for files.
   */
  virtual void registerPath(std::string path) = 0;

  /**
   * Removes all registered paths
   */
  virtual void clear() = 0;

  /**
   * Attempts to find files in all registered paths.
   */
  virtual std::string find(std::string file) = 0;

  /**
   * Returns the size of the file.
   */
  virtual int getSize(std::string file) = 0;

  /**
   * Reads the content of the file into the given buffer.
   */
  virtual int read(std::string file, void* buffer, int size) = 0;

  /**
   * Reads the entire contents of the file.
   */
  virtual std::string readAll(std::string file) = 0;
}; // FilesystemInterface

} // filesystem
} // dioptre

#endif // DIOPTRE_FILESYSTEM_FILESYSTEM_INTERFACE_H_
