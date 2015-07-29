#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>

#include "dioptre/locator.h"
#include "dioptre/module.h"
#include "dioptre/graphics/opengl/graphics.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // Specify an OpenGL 3.3 format using the Core profile.
  // That is, no old-school fixed pipeline functionality
  QSurfaceFormat glFormat;
  glFormat.setVersion( 3, 3 );
  glFormat.setProfile(QSurfaceFormat::OpenGLContextProfile::CoreProfile);
  /* glFormat.setSampleBuffers( true ); */

  QSurfaceFormat::setDefaultFormat(glFormat);

  dioptre::Locator::initialize();
  dioptre::Locator::provide(dioptre::Module::M_GRAPHICS, new dioptre::graphics::opengl::Graphics());

  MainWindow w;
  w.show();

  return a.exec();
}
