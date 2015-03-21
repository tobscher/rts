#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>

#include "dioptre/filesystem/path_lookup.h"

#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>

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

  log4cxx::LoggerPtr rootlogger = log4cxx::Logger::getRootLogger();
  rootlogger->addAppender(new log4cxx::ConsoleAppender(new log4cxx::PatternLayout("%d [%-5p] %c - %m%n")));

  MainWindow w;
  w.show();

  return a.exec();
}
