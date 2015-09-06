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
  /* float x = 0.0; */
  /* float y = 0.0; */

  /* const uint8_t *p; */
  /* for (p = (const uint8_t *)text_.c_str(); *p; p++) { */

  /*   /1* Calculate the vertex and texture coordinates *1/ */
  /*   float x2 = x + atlas_->c[*p].bl; */
  /*   float y2 = -y - atlas_->c[*p].bt; */
  /*   float w = atlas_->c[*p].bw; */
  /*   float h = atlas_->c[*p].bh; */

  /*   /1* Advance the cursor to the start of the next character *1/ */
  /*   x += atlas_->c[*p].ax; */
  /*   y += atlas_->c[*p].ay; */

  /*   /1* Skip glyphs that have no pixels *1/ */
  /*   if (!w || !h) */
  /*     continue; */

  /*   addCombined(glm::vec4{x2,     -y2,     atlas_->c[*p].tx, atlas_->c[*p].ty}); */
  /*   addCombined(glm::vec4{x2 + w, -y2,     atlas_->c[*p].tx + atlas_->c[*p].bw / atlas_->width_, atlas_->c[*p].ty}); */
  /*   addCombined(glm::vec4{x2,     -y2 - h, atlas_->c[*p].tx, atlas_->c[*p].ty + atlas_->c[*p].bh / atlas_->height_}); */
  /*   addCombined(glm::vec4{x2 + w, -y2,     atlas_->c[*p].tx + atlas_->c[*p].bw / atlas_->width_, atlas_->c[*p].ty}); */
  /*   addCombined(glm::vec4{x2,     -y2 - h, atlas_->c[*p].tx, atlas_->c[*p].ty + atlas_->c[*p].bh / atlas_->height_}); */
  /*   addCombined(glm::vec4{x2 + w, -y2 - h, atlas_->c[*p].tx + atlas_->c[*p].bw / atlas_->width_, atlas_->c[*p].ty + atlas_->c[*p].bh / atlas_->height_}); */
  /* } */
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
