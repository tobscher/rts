#ifndef DIOPTRE_OBJECT_H_
#define DIOPTRE_OBJECT_H_

#include <vector>
#include "component_interface.h"

namespace dioptre {

class Object {
public:
  void addComponent(ComponentInterface* component);

  void update();

private:
  std::vector<ComponentInterface*> components_;
};

}

#endif // DIOPTRE_OBJECT_H_
