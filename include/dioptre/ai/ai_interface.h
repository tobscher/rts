#ifndef DIOPTRE_AI_AI_INTERFACE_H_
#define DIOPTRE_AI_AI_INTERFACE_H_

#include "dioptre/module.h"

namespace dioptre {
namespace ai {

class AIInterface : public dioptre::Module {
public:
  AIInterface();
  virtual ~AIInterface() {}
}; // AIInterface
} // ai
} // dioptre

#endif // DIOPTRE_AI_AI_INTERFACE_H_
