#ifndef DIOPTRE_OBJECT_H_
#define DIOPTRE_OBJECT_H_

#include <string>
#include <vector>

#include "component_interface.h"
#include "state.h"

#include "log4cxx/logger.h"

namespace dioptre {

class Object {
public:
  Object(std::string name);
  ~Object();

  // Components
  void addComponent(ComponentInterface* component);

  template <typename T>
  T* getComponent() {
    for (auto component : components_) {
      if (dynamic_cast<T*>(component) != nullptr) {
        return (T*)component;
      }
    }

    return nullptr;
  }

  virtual int initialize();

  // State
  State<Transform>* getState();
  Transform* getTransform();
  virtual void makeCurrent();

  std::string getName();
  bool getIsInitialized();

  void update();

  // Events
  virtual void handleClick(glm::vec3 hitPoint);
protected:
  State<Transform>* state_;
  std::string name_;
  bool isInitialized_;

  log4cxx::LoggerPtr logger_;

private:
  std::vector<ComponentInterface*> components_;
};

}

#endif // DIOPTRE_OBJECT_H_
