#ifndef DIOPTRE_GRAPHICS_OBJECT_H_
#define DIOPTRE_GRAPHICS_OBJECT_H_

namespace dioptre {
namespace graphics {

class Object {
public:
  Object();
  virtual ~Object() {};

  int getId();
private:
  int id_;
}; // Object

} // graphics
} // dioptre

#endif
