#ifndef DIOTRE_GRAPHICS_GEOMETRY_H_
#define DIOTRE_GRAPHICS_GEOMETRY_H_

#include <vector>
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class Geometry {
public:
  virtual ~Geometry() {}
  std::vector<glm::vec3> getData();

  bool isInitialized();
  void setIsInitialized(bool value);

  virtual void initialize() = 0;
  virtual void update() = 0;
  virtual void destroy() = 0;

protected:
  std::vector<glm::vec3> vertices_;

private:
  bool isInitialized_;
}; // Geometry

} // graphics
} // dioptre

#endif
