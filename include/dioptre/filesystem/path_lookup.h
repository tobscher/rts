#ifndef DIOPTRE_FILESYSTEM_PATH_LOOKUP_H_
#define DIOPTRE_FILESYSTEM_PATH_LOOKUP_H_

#include <vector>
#include <string>

namespace dioptre {
namespace filesystem {

/**
 * Class to lookup files from registered paths.
 * This class is a singleton.
 */
class PathLookup {
public:
  /**
   * Accessor method get hold of the underlying instance
   * for this singleton class.
   */
  static PathLookup& instance();

  /*
   * Register path of the exectable as a registered
   * lookup path
   */
  void registerFromArgs(char *argv[]);

  /**
   * Removes all registered paths
   */
  void clear();

  /**
   * Attempts to find files in all registered paths.
   */
  std::string find(std::string file);

protected:
  PathLookup() {}

private:
  std::vector<std::string> paths;
}; // PathLookup

} // filesystem
} // dioptre

#endif // DIOPTRE_FILESYSTEM_PATH_LOOKUP_H_
