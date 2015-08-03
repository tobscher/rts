#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

#include "dioptre/graphics/texture.h"
#include "dioptre/locator.h"

#include "SOIL2.h"

namespace dioptre {
namespace graphics {

Texture::Texture(std::string image) :
  imagePath_(image),
  repeat_(glm::vec2(1,1)) {

  logger_ = spdlog::get("dioptre");

  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);
  auto size = filesystem->getSize(image);
  unsigned char* buffer = new unsigned char[size];
  auto read = filesystem->read(image, buffer, size);

  // Load texture from image path
  image_ = SOIL_load_image_from_memory(buffer, size, &width_, &height_, &components_, SOIL_LOAD_RGBA);

  if (image_ == nullptr) {
    std::stringstream exception;
    exception << imageLoadError
              << image
              << "; Error: "
              << SOIL_last_result();

    throw std::runtime_error(exception.str());
  }

  logger_->info("Texture loaded: ") << image << "; Size: " << width_ << "x" << height_;

  delete buffer;
}

void Texture::setRepeat(glm::vec2 repeat) {
  repeat_ = repeat;
}

} // graphics
} // dioptre
