#ifndef DIOPTRE_BEHAVIOURS_ROTATE_H_
#define DIOPTRE_BEHAVIOURS_ROTATE_H_

#include "dioptre/component_interface.h"

namespace dioptre {
namespace behaviours {

class Rotate : public ComponentInterface {
public:
  void update();
}; // Rotate

}
}

#endif // DIOPTRE_BEHAVIOURS_ROTATE_H_
