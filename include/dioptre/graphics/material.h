#ifndef DIOTRE_GRAPHICS_MATERIAL_H_
#define DIOTRE_GRAPHICS_MATERIAL_H_

#include "glm/vec3.hpp"

namespace dioptre {
namespace graphics {

typedef glm::vec3 color;

class Material {
public:
  virtual ~Material() {}

  bool isInitialized();
  void setIsInitialized(bool value);

  virtual void initialize() = 0;
  virtual void update() = 0;
  virtual void destroy() = 0;

private:
  bool isInitialized_;
}; // Material

} // graphics
} // dioptre

#endif
