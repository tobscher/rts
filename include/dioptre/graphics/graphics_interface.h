#ifndef DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
#define DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_

#include "dioptre/module.h"
#include "dioptre/graphics/layer.h"
#include "dioptre/graphics/debug.h"
#include "dioptre/graphics/projector.h"

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
   * Initializes the current scene.
   */
  virtual void initializeScene() = 0;

  /**
   * Should handles window resize events.
   */
  virtual void resize(int width, int height) = 0;

  /**
   * Should render scene graph.
   */
  virtual void render(const double alpha) = 0;

  /**
   * Updates the graphics service.
   */
  void update();

  /**
   * Should destroy the window.
   */
  virtual void destroy() = 0;

  /**
   * Destroys the given scene.
   */
  virtual void destroyScene(Scene* scene) = 0;

  void setProjector(Projector* projector);

  Layer* getLayer(unsigned int index);
  void addLayer(Layer* layer);
protected:
  std::vector<dioptre::graphics::Layer*> layers_;

  Projector* projector_;
}; // GraphicsInterface

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
