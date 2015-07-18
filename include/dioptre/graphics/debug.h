#ifndef DIOPTRE_GRAPHICS_DEBUG_H_
#define DIOPTRE_GRAPHICS_DEBUG_H_

#include "glm/vec3.hpp"
#include "dioptre/graphics/debug_material.h"
#include "dioptre/graphics/geometry.h"
#include "dioptre/graphics/scene.h"

namespace dioptre {
namespace graphics {

class Debug {
public:
  Debug();
  virtual ~Debug() {}

  virtual int initialize() = 0;
  void reset();
  void destroy();

  Scene* getScene() { return scene_.get(); }

  void addLine(glm::vec3 from, glm::vec3 to);

protected:
  std::unique_ptr<Scene> scene_;

  DebugMaterial* material_;
  Geometry* geometry_;
}; // Debug

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_DEBUG_H_
