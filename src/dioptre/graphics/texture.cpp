#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

#include "dioptre/graphics/texture.h"
#include "dioptre/locator.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace dioptre {
namespace graphics {

Texture::Texture(std::string image) :
  repeat_(glm::vec2(1,1)) {
  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);
  std::string imagePath = filesystem->find(image);

  // Load texture from image path
  image_ = stbi_load(imagePath.c_str(), &width_, &height_, &components_, 0);

  if (image_ == nullptr) {
    std::stringstream exception;
    exception << imageLoadError;
    exception << imagePath;

    throw std::runtime_error(exception.str());
  }
}

void Texture::setRepeat(glm::vec2 repeat) {
  repeat_ = repeat;
}

} // graphics
} // dioptre
