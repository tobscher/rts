#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_H_

#include <string>

#include "dioptre/graphics/opengl.h"

#include "log4cxx/logger.h"

namespace dioptre {
namespace graphics {
namespace opengl {

enum ShaderFeatures {
  FeatureNone = 0,
  FeatureColor = 1,
  FeatureTexture = 2
};

inline ShaderFeatures operator|(ShaderFeatures a, ShaderFeatures b) {
  return static_cast<ShaderFeatures>(static_cast<int>(a) | static_cast<int>(b));
}

inline ShaderFeatures operator&(ShaderFeatures a, ShaderFeatures b) {
  return static_cast<ShaderFeatures>(static_cast<int>(a) & static_cast<int>(b));
}

const std::string USE_COLOR("#define USE_COLOR\n");
const std::string USE_TEXTURE("#define USE_TEXTURE\n");

/**
 * Loads and links shader program for the given file path.
 */
class Shader {
public:
  Shader(ShaderFeatures features);
  GLuint loadFromFile(std::string vertexFilePath, std::string fragmentFilePath);

private:
  bool loaded_;
  GLuint programId_;
  ShaderFeatures features_;

  std::string applyFeatures(std::string code);
  std::string readShaderContent(std::string file);
  bool compileShader(std::string shaderCode, GLuint& shaderId);
  GLuint linkShader(GLuint& vertexShaderId, GLuint fragmentShaderId);

  static log4cxx::LoggerPtr logger_;
}; // Shader

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
