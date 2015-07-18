#include "dioptre/graphics/opengl/shader_factory.h"
#include <sstream>

namespace dioptre {
namespace graphics {
namespace opengl {

std::map<std::string, Shader*> ShaderFactory::shaderPool_;

Shader* ShaderFactory::getShader(ShaderFeatures features, const std::string& vertexShader, const std::string& fragmentShader) {
  std::stringstream cacheKey("shader-");
  cacheKey << features << vertexShader << fragmentShader;

  if (shaderPool_.find(cacheKey.str()) == shaderPool_.end()) {
    Shader* shader = new Shader(features);
    shader->loadFromFile(vertexShader, fragmentShader);

    shaderPool_.insert(std::pair<std::string, Shader*>(cacheKey.str(), shader));
  }

  return shaderPool_[cacheKey.str()];
}

void ShaderFactory::cleanUp() {
  for (auto it = shaderPool_.begin(); it != shaderPool_.end(); it++) {
    delete it->second;
  }
}

} // opengl
} // graphics
} // dioptre
