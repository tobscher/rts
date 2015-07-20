#ifndef DIOPTRE_GRAPHICS_OPENGL_TEXTURE_FACTORY_H_
#define DIOPTRE_GRAPHICS_OPENGL_TEXTURE_FACTORY_H_

#include "dioptre/graphics/opengl/texture.h"

#include <string>
#include <map>

using dioptre::graphics::opengl::Texture;

namespace dioptre {
namespace graphics {
namespace opengl {

class TextureFactory {
public:
  static Texture* getTexture(std::string imagePath);
  static void cleanUp();

private:
  static std::map<std::string, Texture*> texturePool_;
}; // TextureFactory

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_TEXTURE_FACTORY_H_
