#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>

#include "dioptre/filesystem/path_lookup.h"

int main(int argc, char *argv[])
{
  dioptre::filesystem::PathLookup::instance().registerFromArgs(argv);

  QApplication a(argc, argv);

  // Specify an OpenGL 3.3 format using the Core profile.
  // That is, no old-school fixed pipeline functionality
  QSurfaceFormat glFormat;
  glFormat.setVersion( 3, 3 );
  glFormat.setProfile(QSurfaceFormat::OpenGLContextProfile::CoreProfile);
  /* glFormat.setSampleBuffers( true ); */

  QSurfaceFormat::setDefaultFormat(glFormat);

  MainWindow w;
  w.show();

  return a.exec();
}
