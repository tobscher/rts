#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_H_

#include <string>
#include <memory>

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/shader_features.h"

#include "spdlog/spdlog.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class ShaderFactory;
/**
 * Loads and links shader program for the given file path.
 */
class Shader {
friend class ShaderFactory;

public:
  ~Shader();
  GLuint getProgram() { return programId_; }

private:
  Shader(ShaderFeatures features);
  GLuint loadFromFile(std::string vertexFilePath, std::string fragmentFilePath);

  bool loaded_;
  GLuint programId_;
  ShaderFeatures features_;

  std::string applyFeatures(std::string code);
  std::string readShaderContent(std::string file);
  bool compileShader(std::string shaderCode, GLuint& shaderId);
  GLuint linkShader(GLuint& vertexShaderId, GLuint fragmentShaderId);

  static std::shared_ptr<spdlog::logger> logger_;
}; // Shader

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
