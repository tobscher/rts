#ifndef DIOPTRE_GRAPHICS_OPENGL_DEBUG_H_
#define DIOPTRE_GRAPHICS_OPENGL_DEBUG_H_

#include "dioptre/graphics/debug.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class Debug : public dioptre::graphics::Debug {
public:
  Debug(Camera* camera);
  int initialize();
}; // Debug

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_DEBUG_H_
