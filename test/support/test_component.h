#include "dioptre/component_interface.h"

class TestComponent : public dioptre::ComponentInterface {
public:
  TestComponent() : dioptre::ComponentInterface("test_component") {}

  void update() {}
};
