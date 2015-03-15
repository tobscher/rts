#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_H_

#include <string>
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

/**
 * Loads and links shader program for the given file path.
 */
GLuint LoadShaders(std::string vertexFilePath, std::string fragmentFilePath);

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
