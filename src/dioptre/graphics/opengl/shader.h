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
  Shader();
  GLuint loadFromFile(std::string vertexFilePath, std::string fragmentFilePath);
  GLuint identifier();

private:
  bool loaded_;
  GLuint programId_;

  std::string readShaderContent(std::string file);
  bool compileShader(std::string shaderCode, GLuint& shaderId);
  GLuint linkShader(GLuint& vertexShaderId, GLuint fragmentShaderId);

  static log4cxx::LoggerPtr logger_;
}; // Shader

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
