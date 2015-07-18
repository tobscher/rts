#ifndef DIOPTRE_GRAPHICS_NULL_GRAPHICS_H_
#define DIOPTRE_GRAPHICS_NULL_GRAPHICS_H_

#include "dioptre/graphics/graphics_interface.h"

namespace dioptre {
namespace graphics {
namespace null {

class Graphics : public dioptre::graphics::GraphicsInterface {
public:
  int initialize() { return 0; }
  void resize(int width, int height) { }
  void render() { }
  void destroy() { }

  void initializeScene() { }
  void addLine(glm::vec3 from, glm::vec3 to) {}
}; // Graphics

} // null
} // graphics
} // dioptre

#endif
