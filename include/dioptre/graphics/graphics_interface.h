#ifndef DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
#define DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_

#include "dioptre/module.h"
#include "scene.h"
#include "camera.h"
#include "debug.h"
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
  virtual ~GraphicsInterface() { if (debug_) delete debug_; }

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
   * Returns the scene that's used.
   */
  Scene* getScene();

  /**
   * Returns the camera that's used.
   */
  Camera* getCamera();

  /**
   * Should destroy the window.
   */
  virtual void destroy() = 0;

  /**
   * Destroys the given scene.
   */
  virtual void destroyScene(Scene* scene) = 0;

  /**
   * Returns the debug object.
   */
  Debug* getDebug() { return debug_; }

  /**
   * Sets the debug drawer.
   */
  void setDebug(Debug* debug) { debug_ = debug; }

  void setProjector(Projector* projector);
protected:
  std::unique_ptr<Scene> scene_;
  std::unique_ptr<Camera> camera_;

  Projector* projector_;
  Debug* debug_;
}; // GraphicsInterface

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_GRAPHICS_INTERFACE_H_
