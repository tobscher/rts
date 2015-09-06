#include "dioptre/graphics/atlas.h"
#include "dioptre/locator.h"

#include "pugixml.hpp"

namespace dioptre {
namespace graphics {

Atlas::Atlas(std::string file, std::string descriptionFile) :
  file_(file),
  descriptionFile_(descriptionFile),
  image_(nullptr),
  description_(nullptr),
  family_(""),
  height_(-1),
  style_(""),
  size_(-1)
{

}

int Atlas::initialize() {
  loadImage();
  loadDescription();

  return 0;
}

void Atlas::loadImage() {
  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);
  auto size = filesystem->getSize(file_);
  image_ = new unsigned char[size];
  filesystem->read(file_, image_, size);
}

void Atlas::loadDescription() {
  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);

  auto size = filesystem->getSize(descriptionFile_);
  description_ = new unsigned char[size];
  filesystem->read(descriptionFile_, description_, size);

  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_buffer(description_, size);
  pugi::xml_node font = doc.child("Font");

  family_ = font.attribute("family").value();
  height_ = atoi(font.attribute("height").value());
  style_ = font.attribute("style").value();
  size_ = atoi(font.attribute("size").value());

  for (pugi::xml_node charNode = font.child("Char"); charNode; charNode = charNode.next_sibling("Char")) {
    Char charDescription;
    std::sscanf(charNode.attribute("rect").value(),
        "%i %i %i %i",
        &charDescription.placeX,
        &charDescription.placeY,
        &charDescription.placeW,
        &charDescription.placeH);

    char c;

    std::sscanf(charNode.attribute("code").value(),
        "%c",
        &c);

    charDescription.width = atoi(charNode.attribute("width").value());

    std::sscanf(charNode.attribute("offset").value(),
        "%i %i",
        &charDescription.offsetX,
        &charDescription.offsetY);

    charMap_.insert(std::pair<char, Char>(c, charDescription));
  }
}

unsigned char* Atlas::getImage() {
  return image_;
}

unsigned char* Atlas::getDescription() {
  return description_;
}

std::string Atlas::getFamily() {
  return family_;
}

int Atlas::getHeight() {
  return height_;
}

std::string Atlas::getStyle() {
  return style_;
}

int Atlas::getSize() {
  return size_;
}

Atlas::Char Atlas::getChar(char c) {
  if (charMap_.find(c) != charMap_.end()) {
    return charMap_[c];
  }

  Atlas::Char empty;
  return empty;
}

} // graphics
} // dioptre
