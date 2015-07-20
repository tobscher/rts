#include "dioptre/graphics/opengl/texture_factory.h"

namespace dioptre {
namespace graphics {
namespace opengl {

std::map<std::string, Texture*> TextureFactory::texturePool_;

Texture* TextureFactory::getTexture(std::string imagePath) {
  if (texturePool_.find(imagePath) == texturePool_.end()) {
    Texture* texture = new Texture(imagePath);

    texturePool_.insert(std::pair<std::string, Texture*>(imagePath, texture));
  }

  return texturePool_[imagePath];
}

void TextureFactory::cleanUp() {
  for (auto it = texturePool_.begin(); it != texturePool_.end(); it++) {
    delete it->second;
  }
}

} // opengl
} // graphics
} // dioptre
