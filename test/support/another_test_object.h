#ifndef ANOTHER_TEST_OBJECT_H_
#define ANOTHER_TEST_OBJECT_H_

#include "dioptre/object.h"

class AnotherTestObject : public dioptre::Object {
public:
  AnotherTestObject() : dioptre::Object("another_test_object") {}
};

#endif // ANOTHER_TEST_OBJECT_H_
