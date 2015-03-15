SET (project_BIN ${PROJECT_NAME}-editor)
SET (project_LIBS libglew_static ${OPENGL_LIBRARIES})

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5OpenGL)

ADD_EXECUTABLE(
  ${project_BIN}
  main.cpp
  mainwindow.cpp
  glwidget.cpp
)
TARGET_LINK_LIBRARIES(
  ${project_BIN}
  ${project_LIBS}
  engine
  Qt5::Widgets
  Qt5::OpenGL
)
