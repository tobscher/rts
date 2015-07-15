#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

#include "dioptre/graphics/texture.h"
#include "dioptre/locator.h"

#include "SOIL.h"

namespace dioptre {
namespace graphics {

Texture::Texture(std::string image) :
  repeat_(glm::vec2(1,1)) {
  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);
  auto size = filesystem->getSize(image);
  unsigned char* buffer = new unsigned char[size];
  auto read = filesystem->read(image, buffer, size);

  // Load texture from image path
  image_ = SOIL_load_image_from_memory(buffer, size, &width_, &height_, &components_, SOIL_LOAD_RGBA);

  if (image_ == nullptr) {
    std::stringstream exception;
    exception << imageLoadError;
    exception << image;
    exception << SOIL_last_result();
    exception << buffer;

    throw std::runtime_error(exception.str());
  }
}

void Texture::setRepeat(glm::vec2 repeat) {
  repeat_ = repeat;
}

} // graphics
} // dioptre
