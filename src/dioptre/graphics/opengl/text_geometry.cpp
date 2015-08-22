#include "dioptre/graphics/opengl/text_geometry.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/debug.h"

using dioptre::graphics::opengl::BufferManager;
using dioptre::graphics::opengl::Atlas;

namespace dioptre {
namespace graphics {
namespace opengl {

TextGeometry::TextGeometry(std::string text, glm::vec2 position, Atlas* atlas) :
  dioptre::graphics::TextGeometry(text, position),
  atlas_(atlas)
{
  bufferManager_ = std::unique_ptr<BufferManager>(new BufferManager(this));
}

void TextGeometry::initialize() {
  if (!atlas_->getIsInitialized()) {
    atlas_->initialize();
  }

  // Use window service
  float sx = 2.0 / 1280.0;
  float sy = 2.0 / 800.0;

  float x = position_.x * sx;
  float y = position_.y * sy;

  std::cout << "Render text at: " << x << "x" << y << std::endl;

  const uint8_t *p;
  for (p = (const uint8_t *)text_.c_str(); *p; p++) {

    /* Calculate the vertex and texture coordinates */
    float x2 = x + atlas_->c[*p].bl * sx;
    float y2 = -y - atlas_->c[*p].bt * sy;
    float w = atlas_->c[*p].bw * sx;
    float h = atlas_->c[*p].bh * sy;

    /* Advance the cursor to the start of the next character */
    x += atlas_->c[*p].ax * sx;
    y += atlas_->c[*p].ay * sy;

    /* Skip glyphs that have no pixels */
    if (!w || !h)
      continue;

    addCombined(glm::vec4{x2,     -y2,     atlas_->c[*p].tx, atlas_->c[*p].ty});
    addCombined(glm::vec4{x2 + w, -y2,     atlas_->c[*p].tx + atlas_->c[*p].bw / atlas_->width_, atlas_->c[*p].ty});
    addCombined(glm::vec4{x2,     -y2 - h, atlas_->c[*p].tx, atlas_->c[*p].ty + atlas_->c[*p].bh / atlas_->height_});
    addCombined(glm::vec4{x2 + w, -y2,     atlas_->c[*p].tx + atlas_->c[*p].bw / atlas_->width_, atlas_->c[*p].ty});
    addCombined(glm::vec4{x2,     -y2 - h, atlas_->c[*p].tx, atlas_->c[*p].ty + atlas_->c[*p].bh / atlas_->height_});
    addCombined(glm::vec4{x2 + w, -y2 - h, atlas_->c[*p].tx + atlas_->c[*p].bw / atlas_->width_, atlas_->c[*p].ty + atlas_->c[*p].bh / atlas_->height_});
  }

  bufferManager_->initializeCombinedBuffer();
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

} // opengl
} // graphics
} // dioptre
