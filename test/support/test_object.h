#ifndef TEST_OBJECT_H_
#define TEST_OBJECT_H_

#include "dioptre/object.h"

class TestObject : public dioptre::Object {
public:
  TestObject() : dioptre::Object("test_object") {}
};

#endif // TEST_OBJECT_H_
