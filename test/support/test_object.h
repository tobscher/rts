#include "dioptre/object.h"

class TestObject : public dioptre::Object {
public:
  TestObject() : dioptre::Object("test_object") {}
};
