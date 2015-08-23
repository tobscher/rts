#include "rts/text.h"

#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/text_material.h"
#include "dioptre/graphics/opengl/text_geometry.h"
#include "dioptre/font/freetype/face.h"

namespace rts {

Text* Text::spawn() {
  auto fontFace = new dioptre::font::freetype::Face("FreeSans.ttf");
  auto atlas = new dioptre::graphics::opengl::Atlas(fontFace, 48);

  auto material = new dioptre::graphics::opengl::TextMaterial(atlas);
  material->setColor(dioptre::graphics::color(1.0f, 1.0f, 1.0f));

  auto geometry = new dioptre::graphics::opengl::TextGeometry("This is text.", glm::vec2(10,10), atlas);

  Text* text = new Text();

  // Graphics Component
  auto mesh = new dioptre::graphics::Mesh(geometry, material);
  auto visual = new dioptre::graphics::Component(mesh);
  text->addComponent(visual);

  return text;
}

} // rts
