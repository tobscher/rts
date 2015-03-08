#ifndef DIOPTRE_GRAPHICS_RENDERER_INTERFACE_
#define DIOPTRE_GRAPHICS_RENDERER_INTERFACE_

namespace dioptre {
namespace graphics {

class RendererInterface {
public:
  virtual int Initialize() = 0;
  virtual void Resize(int width, int height) = 0;
  virtual void Render() = 0;
};

}
}

#endif
