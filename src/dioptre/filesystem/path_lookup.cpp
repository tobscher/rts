#include <boost/filesystem.hpp>
#include "dioptre/filesystem/path_lookup.h"

namespace dioptre {
namespace filesystem {

PathLookup& PathLookup::instance() {
  static PathLookup *instance = new PathLookup();

  return *instance;
}

void PathLookup::registerFromArgs(char *argv[]) {
  auto f = argv[0];
  auto absolute = boost::filesystem::absolute(f).remove_leaf();

  paths.push_back(absolute.string());
}

void PathLookup::clear() {
  paths.clear();
}

std::string PathLookup::find(std::string file) {
  if (paths.size() == 0) return file;

  boost::filesystem::path base = paths[0];
  base /= file;

  return base.string();
}

}
}
