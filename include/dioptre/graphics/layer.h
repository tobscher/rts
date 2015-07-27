#ifndef DIOPTRE_GRAPHICS_LAYER_H_
#define DIOPTRE_GRAPHICS_LAYER_H_

#include "dioptre/graphics/scene.h"
#include "dioptre/graphics/camera.h"

namespace dioptre {
namespace graphics {

class Layer {
public:
  Layer(Scene* scene, Camera* camera);

  /**
   * Returns the scene that's used.
   */
  Scene* getScene();

  /**
   * Returns the camera that's used.
   */
  Camera* getCamera();

protected:
  std::unique_ptr<dioptre::graphics::Camera> camera_;
  std::unique_ptr<dioptre::graphics::Scene> scene_;
};

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_LAYER_H_
