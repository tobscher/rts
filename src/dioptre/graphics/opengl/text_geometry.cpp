#include "dioptre/graphics/opengl/text_geometry.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/locator.h"
#include "dioptre/debug.h"

using dioptre::graphics::opengl::BufferManager;
using dioptre::graphics::opengl::Atlas;

namespace dioptre {
namespace graphics {
namespace opengl {

TextGeometry::TextGeometry(std::string text, Atlas* atlas) :
  dioptre::graphics::TextGeometry(text),
  atlas_(atlas)
{
  bufferManager_ = std::unique_ptr<BufferManager>(new BufferManager(this));
}

void TextGeometry::initialize() {
  if (!atlas_->getIsInitialized()) {
    atlas_->initialize();
  }

  calculate();

  bufferManager_->initializeCombinedBuffer();
}

void TextGeometry::calculate() {
  float x = 0.0;
  float y = 0.0;

  auto width = (float)atlas_->getWidth();
  auto height = (float)atlas_->getHeight();

  for (auto it = text_.begin(); it != text_.end(); it++) {
    auto charDescription = atlas_->getChar(*it);

    /* Calculate the vertex and texture coordinates */
    float x2 = x + charDescription.offsetX;
    float y2 = -y + charDescription.offsetY;
    float w = charDescription.placeW;
    float h = charDescription.placeH;

    x += charDescription.width;

    /* Skip glyphs that have no pixels */
    if (!w || !h)
      continue;

    auto tx = charDescription.placeX / width;
    auto ty = charDescription.placeY / height;

    addCombined(glm::vec4{x2,     -y2,     tx, ty});
    addCombined(glm::vec4{x2 + w, -y2,     tx + charDescription.placeW / width, ty});
    addCombined(glm::vec4{x2,     -y2 - h, tx, ty + charDescription.placeH / height});
    addCombined(glm::vec4{x2 + w, -y2,     tx + charDescription.placeW / width, ty});
    addCombined(glm::vec4{x2,     -y2 - h, tx, ty + charDescription.placeH / height});
    addCombined(glm::vec4{x2 + w, -y2 - h, tx + charDescription.placeW / width, ty + charDescription.placeH / height});
  }
}

void TextGeometry::update() {
  auto data = getCombinedData();

  bufferManager_->setCombinedBuffer();
  glDrawArrays(GL_TRIANGLES, 0, data.size());
  bufferManager_->disableCombinedBuffer();
}

void TextGeometry::destroy() {
  bufferManager_->destroyVertexBuffer();
}

void TextGeometry::setText(std::string text) {
  dioptre::graphics::TextGeometry::setText(text);

  clearCombined();
  calculate();
}

} // opengl
} // graphics
} // dioptre
