#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_FACTORY_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_FACTORY_H_

#include "dioptre/graphics/opengl/shader.h"

#include <string>
#include <map>

using dioptre::graphics::opengl::Shader;

namespace dioptre {
namespace graphics {
namespace opengl {

class ShaderFactory {
public:
  static Shader* getShader(ShaderFeatures features, const std::string& vertexShader, const std::string& fragmentShader);
  static void cleanUp();

private:
  static std::map<std::string, Shader*> shaderPool_;
};

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_SHADER_FACTORY_H_
