#ifndef DIOPTRE_GRAPHICS_OPENGL_ATLAS_H_
#define DIOPTRE_GRAPHICS_OPENGL_ATLAS_H_

#include "dioptre/graphics/atlas.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class Atlas : public dioptre::graphics::Atlas {
public:
  Atlas(std::string file, std::string descriptionFile);
  ~Atlas();

  int initialize();
  bool getIsInitialized() { return isInitialized_; }

  void updateGL(GLuint programId);

private:
  bool isInitialized_;

  int index_;
  GLuint texture_;
  GLint textureLocation_;
}; // Atlas

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_ATLAS_H_
