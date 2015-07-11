#ifndef DIOTRE_GRAPHICS_MATERIAL_H_
#define DIOTRE_GRAPHICS_MATERIAL_H_

#include "glm/glm.hpp"
#include "log4cxx/logger.h"

namespace dioptre {
namespace graphics {

typedef glm::vec3 color;

class Material {
public:
  Material();
  virtual ~Material() {}

  bool isInitialized();
  void setIsInitialized(bool value);

  virtual void initialize() = 0;
  virtual void update() = 0;
  virtual void destroy() = 0;
  virtual void setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) = 0;

protected:
  log4cxx::LoggerPtr logger_;

private:
  bool isInitialized_;
}; // Material

} // graphics
} // dioptre

#endif
