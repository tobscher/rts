#ifndef DIOPTRE_GRAPHICS_RENDERER_INTERFACE_H_
#define DIOPTRE_GRAPHICS_RENDERER_INTERFACE_H_

namespace dioptre {
namespace graphics {

/**
 * Interface that describes a renderer.
 */
class RendererInterface {
public:

  /**
   * Should initialize graphics context.
   */
  virtual int Initialize() = 0;

  /**
   * Should handles window resize events.
   */
  virtual void Resize(int width, int height) = 0;

  /**
   * Should render screne graph.
   */
  virtual void Render() = 0;
}; // RenderInterface

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_RENDERER_INTERFACE_H_
