#include "dioptre/object.h"

class AnotherTestObject : public dioptre::Object {
public:
  AnotherTestObject() : dioptre::Object("another_test_object") {}
};
