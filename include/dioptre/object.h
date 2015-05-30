#ifndef DIOPTRE_OBJECT_H_
#define DIOPTRE_OBJECT_H_

#include <vector>
#include "component_interface.h"
#include "dioptre/graphics/component.h"

namespace dioptre {

class Object {
public:
  void addComponent(ComponentInterface* component);
  void addComponent(dioptre::graphics::Component* component);

  template<typename T>
  T* getComponent();

  void update();

private:
  std::vector<ComponentInterface*> components_;
  std::vector<dioptre::graphics::Component*> graphicsComponents_;
};

}

#endif // DIOPTRE_OBJECT_H_
