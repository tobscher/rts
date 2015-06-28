#ifndef DIOPTRE_GRAPHICS_TEXTURE_H_
#define DIOPTRE_GRAPHICS_TEXTURE_H_

#include <string>

#include "glm/vec2.hpp"

namespace dioptre {
namespace graphics {

const std::string imageLoadError = "Unable to load image from path: ";

class Texture {
public:
  Texture(std::string imagePath);
  virtual ~Texture() {}

  virtual int initialize() = 0;
  virtual void update() = 0;
  virtual void destroy() = 0;

  void setRepeat(glm::vec2 repeat);

protected:
  unsigned char* image_;

  int width_;
  int height_;
  int components_;

  glm::vec2 repeat_;
};

}
}

#endif // DIOPTRE_GRAPHICS_TEXTURE_H_
