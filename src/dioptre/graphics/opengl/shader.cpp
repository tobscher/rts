#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "shader.h"
#include "dioptre/filesystem/path_lookup.h"
#include "dioptre/graphics/opengl.h"

using std::string;

namespace dioptre {

namespace graphics {
namespace opengl {

/**
 * Reads the content of the given file.
 */
std::string readShaderContent(string file) {
  string filePath = dioptre::filesystem::PathLookup::instance().find(file);
  std::cout << "Loading shader: " << filePath << std::endl;

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
bool compileShader(string shaderCode, GLuint& shaderId) {
  std::cout << "Compiling shader..." << std::endl;

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

    std::cout << &shaderErrorMessage[0] << std::endl;
    return false;
	}

  return true;
}

/**
 * Links the vertex shader and fragment shader.
 */
GLuint linkShader(GLuint& vertexShaderId, GLuint fragmentShaderId) {
  std::cout << "Linking program..." << std::endl;

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
    std::cout << &programErrorMessage[0] << std::endl;
	}

  return programId;
}

GLuint LoadShaders(string vertexFilePath, string fragmentFilePath) {
	// Create the shaders
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

  // Read the contents of the files
  string vertexShaderCode = readShaderContent(vertexFilePath);
  string fragmentShaderCode = readShaderContent(fragmentFilePath);

  // Compile the shaders
  compileShader(vertexShaderCode, vertexShaderId);
  compileShader(fragmentShaderCode, fragmentShaderId);

  // Link the shaders
  GLuint programId = linkShader(vertexShaderId, fragmentShaderId);

  // Delete the reference
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	return programId;
}

}
}
}
