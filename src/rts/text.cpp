#include "rts/text.h"

#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/text_material.h"
#include "dioptre/graphics/opengl/text_geometry.h"

namespace rts {

Text* Text::spawn() {
  auto atlas = new dioptre::graphics::opengl::Atlas("open_sans_bold_14.PNG", "open_sans_bold_14.xml");

  auto material = new dioptre::graphics::opengl::TextMaterial(atlas);
  material->setColor(dioptre::graphics::color(1.0f, 1.0f, 1.0f));

  auto geometry = new dioptre::graphics::opengl::TextGeometry("", atlas);

  Text* text = new Text();
  text->getTransform()->setPosition(520,50,0);

  // Graphics Component
  auto mesh = new dioptre::graphics::Mesh(geometry, material);
  auto visual = new dioptre::graphics::Component(mesh, 1);
  text->addComponent(visual);

  return text;
}

} // rts
