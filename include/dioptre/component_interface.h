#ifndef DIOPTRE_COMPONENT_INTERFACE_H_
#define DIOPTRE_COMPONENT_INTERFACE_H_

namespace dioptre {

class Object;
class ComponentInterface {
public:
  virtual ~ComponentInterface() {}

  virtual void update() = 0;
  void setObject(Object* object);
  Object* getObject();

private:
  Object* object_;
}; // ComponentInterface

} // dioptre

#endif // DIOPTRE_COMPONENT_INTERFACE_H_
