#include "dioptre/graphics/atlas.h"
#include "dioptre/locator.h"

#include "pugixml.hpp"
#include "SOIL2.h"

namespace dioptre {
namespace graphics {

Atlas::Atlas(std::string file, std::string descriptionFile)
    : file_(file), descriptionFile_(descriptionFile), image_(nullptr),
      description_(nullptr), width_(-1), height_(-1), components_(-1),
      family_(""), fontHeight_(-1), style_(""), size_(-1) {}

int Atlas::initialize() {
  loadImage();
  loadDescription();

  return 0;
}

void Atlas::loadImage() {
  auto filesystem =
      dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(
          dioptre::Module::M_FILESYSTEM);
  auto size = filesystem->getSize(file_);
  unsigned char *buffer = new unsigned char[size];
  filesystem->read(file_, buffer, size);

  // Load texture from image path
  image_ = SOIL_load_image_from_memory(buffer, size, &width_, &height_,
                                       &components_, SOIL_LOAD_RGBA);

  if (image_ == nullptr) {
    std::stringstream exception;
    exception << "Error: " << SOIL_last_result();

    throw std::runtime_error(exception.str());
  }

  delete buffer;
}

void Atlas::loadDescription() {
  auto filesystem =
      dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(
          dioptre::Module::M_FILESYSTEM);

  auto size = filesystem->getSize(descriptionFile_);
  description_ = new unsigned char[size];
  filesystem->read(descriptionFile_, description_, size);

  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_buffer(description_, size);
  pugi::xml_node font = doc.child("Font");

  family_ = font.attribute("family").value();
  fontHeight_ = atoi(font.attribute("height").value());
  style_ = font.attribute("style").value();
  size_ = atoi(font.attribute("size").value());

  for (pugi::xml_node charNode = font.child("Char"); charNode;
       charNode = charNode.next_sibling("Char")) {
    Char charDescription;
    std::sscanf(charNode.attribute("rect").value(), "%i %i %i %i",
                &charDescription.placeX, &charDescription.placeY,
                &charDescription.placeW, &charDescription.placeH);

    char c;

    std::sscanf(charNode.attribute("code").value(), "%c", &c);

    charDescription.width = atoi(charNode.attribute("width").value());

    std::sscanf(charNode.attribute("offset").value(), "%i %i",
                &charDescription.offsetX, &charDescription.offsetY);

    charMap_.insert(std::pair<char, Char>(c, charDescription));
  }
}

unsigned char *Atlas::getImage() { return image_; }

unsigned char *Atlas::getDescription() { return description_; }

int Atlas::getHeight() { return height_; }

int Atlas::getWidth() { return width_; }

int Atlas::getComponents() { return components_; }

std::string Atlas::getFamily() { return family_; }

int Atlas::getFontHeight() { return fontHeight_; }

std::string Atlas::getStyle() { return style_; }

int Atlas::getSize() { return size_; }

Atlas::Char Atlas::getChar(char c) {
  if (charMap_.find(c) != charMap_.end()) {
    return charMap_[c];
  }

  Atlas::Char empty;
  return empty;
}

} // graphics
} // dioptre
