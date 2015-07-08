#ifndef DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
#define DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_

#include "dioptre/module.h"
#include "scene.h"
#include "camera.h"
#include <memory>

namespace dioptre {
namespace graphics {

/**
 * Interface that describes a graphics module.
 */
class GraphicsInterface : public Module {
public:
  GraphicsInterface();
  virtual ~GraphicsInterface() {}

  /**
   * Should initialize graphics context.
   */
  virtual int initialize() = 0;

  /**
   * Should handles window resize events.
   */
  virtual void resize(int width, int height) = 0;

  /**
   * Should render scene graph.
   */
  virtual void render() = 0;

  /**
   * Updates the graphics service.
   */
  void update();

  /**
   * Returns the scene that's used.
   */
  Scene* getScene();

  /**
   * Should destroy the window.
   */
  virtual void destroy() = 0;

protected:
  std::unique_ptr<Scene> scene_;
  std::unique_ptr<Camera> camera_;
}; // GraphicsInterface

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
