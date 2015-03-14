#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_H_

#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

}
}
}
#endif
