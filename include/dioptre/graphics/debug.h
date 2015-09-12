#ifndef DIOPTRE_GRAPHICS_DEBUG_H_
#define DIOPTRE_GRAPHICS_DEBUG_H_

#include "glm/vec3.hpp"
#include "dioptre/graphics/debug_material.h"
#include "dioptre/graphics/geometry.h"
#include "dioptre/graphics/layer.h"

#include <memory>

namespace dioptre {
namespace graphics {

class Debug : public Layer {
public:
  explicit Debug(Camera *camera);
  virtual ~Debug() {}

  virtual int initialize() = 0;
  void reset();
  void destroy();

  void addLine(glm::vec3 from, glm::vec3 to);
  void addCross(glm::vec3 point);

protected:
  DebugMaterial *material_;
  Geometry *lines_;
  Geometry *crosses_;
}; // Debug

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_DEBUG_H_
