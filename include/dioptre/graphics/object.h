#ifndef DIOPTRE_GRAPHICS_OBJECT_H_
#define DIOPTRE_GRAPHICS_OBJECT_H_

#include "dioptre/graphics/transform.h"

namespace dioptre {
namespace graphics {

class Object {
public:
  Object();
  virtual ~Object() {};

  int getId();
  Transform getTransform();

private:
  int id_;

  Transform transform_;
}; // Object

} // graphics
} // dioptre

#endif
