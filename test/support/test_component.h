#ifndef TEST_COMPONENT_H_
#define TEST_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/object.h"
#include "glm/glm.hpp"

#include "dioptre/observer.h"

class TestComponent : public dioptre::ComponentInterface,
                      public dioptre::Observer<dioptre::Transform> {
public:
  TestComponent() : dioptre::ComponentInterface("test_component") {}
  void update() {}
  void changed(dioptre::Transform *t) { position_ = t->getPosition(); }
  glm::vec3 getPosition() { return position_; }

private:
  glm::vec3 position_;
};

#endif // TEST_COMPONENT_H_
