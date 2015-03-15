#ifndef DIOPTRE_GRAPHICS_OPENGL_SHADER_H_
#define DIOPTRE_GRAPHICS_OPENGL_SHADER_H_

#include <boost/filesystem/path.hpp>
#include "dioptre/graphics/opengl.h"

extern boost::filesystem::path g_lookupPath;

namespace dioptre {
namespace graphics {
namespace opengl {

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

}
}
}
#endif
