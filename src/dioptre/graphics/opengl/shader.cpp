#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "dioptre/graphics/opengl/shader.h"
#include "dioptre/graphics/opengl/shader_features.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/locator.h"

using std::string;

namespace dioptre {
namespace graphics {
namespace opengl {

Shader::Shader(ShaderFeatures features) :
  loaded_(false),
  features_(features) {
}

/**
 * Reads the content of the given file.
 */
std::string Shader::readShaderContent(string file) {
  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);
  string filePath = filesystem->find(file);

  LOG4CXX_INFO(Shader::logger_, "Loading shader: " + filePath);

  string shaderCode;
  std::ifstream shaderStream(filePath.c_str(), std::ios::in);

  if (shaderStream.is_open()) {
    string line;
    while (getline(shaderStream, line)) {
      shaderCode += "\n" + line;
    }
    shaderStream.close();
  }

  return shaderCode;
}

/**
 * Compiles the given shader code
 */
bool Shader::compileShader(string shaderCode, GLuint& shaderId) {
  LOG4CXX_INFO(Shader::logger_, "Compiling shader");

  // compile
  char const * shaderSourcePointer = shaderCode.c_str();
  glShaderSource(shaderId, 1, &shaderSourcePointer , NULL);
  glCompileShader(shaderId);

  // check
  GLint result = GL_FALSE;
  int infoLogLength;
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
  glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
  if (infoLogLength > 0) {
    std::vector<char> shaderErrorMessage(infoLogLength + 1);
    glGetShaderInfoLog(shaderId, infoLogLength, NULL, &shaderErrorMessage[0]);

    LOG4CXX_ERROR(Shader::logger_, &shaderErrorMessage[0]);
    return false;
  }

  return true;
}

/**
 * Links the vertex shader and fragment shader.
 */
GLuint Shader::linkShader(GLuint& vertexShaderId, GLuint fragmentShaderId) {
  LOG4CXX_INFO(Shader::logger_, "Linking program...");

  GLuint programId = glCreateProgram();
  glAttachShader(programId, vertexShaderId);
  glAttachShader(programId, fragmentShaderId);
  glLinkProgram(programId);

  // Check the program
  GLint result = GL_FALSE;
  int infoLogLength;
  glGetProgramiv(programId, GL_LINK_STATUS, &result);
  glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
  if (infoLogLength > 0) {
    std::vector<char> programErrorMessage(infoLogLength + 1);
    glGetProgramInfoLog(programId, infoLogLength, NULL, &programErrorMessage[0]);
    LOG4CXX_ERROR(Shader::logger_, &programErrorMessage[0]);
  }

  return programId;
}

GLuint Shader::loadFromFile(string vertexFilePath, string fragmentFilePath) {
  if (loaded_) {
    return programId_;
  }

  // Create the shaders
  GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

  // Read the contents of the files
  string vertexShaderCode = readShaderContent(vertexFilePath);
  string fragmentShaderCode = readShaderContent(fragmentFilePath);

  vertexShaderCode = applyFeatures(vertexShaderCode);
  fragmentShaderCode = applyFeatures(fragmentShaderCode);

  // Compile the shaders
  compileShader(vertexShaderCode, vertexShaderId);
  compileShader(fragmentShaderCode, fragmentShaderId);

  // Link the shaders
  programId_ = linkShader(vertexShaderId, fragmentShaderId);

  // Delete the reference
  glDeleteShader(vertexShaderId);
  glDeleteShader(fragmentShaderId);

  loaded_ = true;

  return programId_;
}

string Shader::applyFeatures(string code) {
  if ((features_ & FeatureColor) == FeatureColor) {
    code.insert(19, USE_COLOR);
  }

  if ((features_ & FeatureTexture) == FeatureTexture) {
    code.insert(19, USE_TEXTURE);
  }

  return code;
}

log4cxx::LoggerPtr Shader::logger_ = log4cxx::Logger::getLogger("dioptre.shader");

} // opengl
} // graphics
} // dioptre
