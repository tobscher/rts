#ifndef DIOPTRE_OBJECT_H_
#define DIOPTRE_OBJECT_H_

#include <string>
#include <vector>

#include "component_interface.h"
#include "dioptre/graphics/component.h"

#include "log4cxx/logger.h"

namespace dioptre {

class Object {
public:
  Object(std::string name);
  ~Object();

  void addComponent(ComponentInterface* component);
  void addComponent(dioptre::graphics::Component* component);

  template<typename T>
  T* getComponent();

  void update();

protected:
  std::string name_;
  log4cxx::LoggerPtr logger_;

private:
  std::vector<ComponentInterface*> components_;
  std::vector<dioptre::graphics::Component*> graphicsComponents_;
};

}

#endif // DIOPTRE_OBJECT_H_
