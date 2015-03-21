#ifndef DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
#define DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_

#include "dioptre/module.h"

namespace dioptre {
namespace graphics {

/**
 * Interface that describes a graphics module.
 */
class GraphicsInterface : public Module {
public:
  virtual ~GraphicsInterface() {}

  /**
   * Should initialize graphics context.
   */
  virtual int Initialize() = 0;

  /**
   * Should handles window resize events.
   */
  virtual void Resize(int width, int height) = 0;

  /**
   * Should render scene graph.
   */
  virtual void Render() = 0;

  /**
   * Should destroy the window.
   */
  virtual void Destroy() = 0;
}; // GraphicsInterface

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
