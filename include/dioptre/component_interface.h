#ifndef DIOPTRE_COMPONENT_INTERFACE_H_
#define DIOPTRE_COMPONENT_INTERFACE_H_

#include <string>

#include "log4cxx/logger.h"

namespace dioptre {

class Object;
class ComponentInterface {
public:
  ComponentInterface(std::string name);
  virtual ~ComponentInterface() {}

  virtual int initialize();
  virtual void update() = 0;
  void setObject(Object* object);
  Object* getObject();

  bool getIsInitialized();

protected:
  std::string name_;
  bool isInitialized_;

  log4cxx::LoggerPtr logger_;

private:
  Object* object_;
}; // ComponentInterface

} // dioptre

#endif // DIOPTRE_COMPONENT_INTERFACE_H_
