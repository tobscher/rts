#include "dioptre/module.h"

namespace dioptre {

Module::Module(std::string name) :
  name_(name) {
  logger_ = spdlog::get("dioptre");
}


} // dioptre
