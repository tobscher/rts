#ifndef DIOPTRE_OBJECT_H_
#define DIOPTRE_OBJECT_H_

#include <string>
#include <vector>

#include "component_interface.h"
#include "transform.h"

#include "log4cxx/logger.h"

namespace dioptre {

class Object {
public:
  Object(std::string name);
  ~Object();

  void addComponent(ComponentInterface* component);

  template<typename T>
  T* getComponent();

  Transform* getTransform() { return transform_; }
  std::string getName() { return name_; }

  void update();

protected:
  Transform* transform_;

  std::string name_;
  log4cxx::LoggerPtr logger_;

private:
  std::vector<ComponentInterface*> components_;
};

}

#endif // DIOPTRE_OBJECT_H_
