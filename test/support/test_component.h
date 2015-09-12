#ifndef TEST_COMPONENT_H_
#define TEST_COMPONENT_H_

#include "dioptre/component_interface.h"

class TestComponent : public dioptre::ComponentInterface {
public:
  TestComponent() : dioptre::ComponentInterface("test_component") {}

  void update() {}
};

#endif // TEST_COMPONENT_H_
