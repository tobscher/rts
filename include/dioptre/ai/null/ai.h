#ifndef DIOPTRE_AI_NULL_AI_H_
#define DIOPTRE_AI_NULL_AI_H_

#include "dioptre/ai/ai_interface.h"

namespace dioptre {
namespace ai {
namespace null {

class AI : public dioptre::ai::AIInterface {
public:
  int initialize() { return 0; }
  void destroy() {}
}; // AI
} // null
} // ai
} // dioptre

#endif // DIOPTRE_AI_NULL_AI_H_
