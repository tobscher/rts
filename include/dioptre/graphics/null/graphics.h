#ifndef DIOPTRE_GRAPHICS_NULL_GRAPHICS_H_
#define DIOPTRE_GRAPHICS_NULL_GRAPHICS_H_

#include "dioptre/graphics/graphics_interface.h"

namespace dioptre {
namespace graphics {
namespace null {

class Graphics : public dioptre::graphics::GraphicsInterface {
public:
  int Initialize() { return 0; }
  void Resize(int width, int height) { }
  void Render() { }
  void Destroy() { }
}; // Graphics

} // null
} // graphics
} // dioptre

#endif
