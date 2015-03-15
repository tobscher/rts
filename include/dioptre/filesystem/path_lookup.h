#ifndef DIOPTRE_FILESYSTEM_PATH_LOOKUP_H_
#define DIOPTRE_FILESYSTEM_PATH_LOOKUP_H_

#include <vector>
#include <string>

namespace dioptre {
namespace filesystem {

class PathLookup {
public:
  static PathLookup& instance();

  void registerFromArgs(char *argv[]);
  void clear();
  std::string find(std::string file);

protected:
  PathLookup() {}

private:
  std::vector<std::string> paths;
};

}
}

#endif
