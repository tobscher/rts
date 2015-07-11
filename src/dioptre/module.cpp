#include "dioptre/module.h"

namespace dioptre {

Module::Module(std::string name) :
  name_(name) {
  logger_ = log4cxx::Logger::getLogger(name);
}


} // dioptre
