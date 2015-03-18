#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_H_

#include <string>
#include "dioptre/graphics/opengl.h"

#include "log4cxx/logger.h"

namespace dioptre {
namespace graphics {
namespace opengl {

/**
 * Loads and links shader program for the given file path.
 */
class Shader {
public:
  static GLuint LoadShaders(std::string vertexFilePath, std::string fragmentFilePath);

private:
  static std::string readShaderContent(std::string file);
  static bool compileShader(std::string shaderCode, GLuint& shaderId);
  static GLuint linkShader(GLuint& vertexShaderId, GLuint fragmentShaderId);

  static log4cxx::LoggerPtr logger_;
};

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
