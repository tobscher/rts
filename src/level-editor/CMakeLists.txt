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

# Copy shaders
add_custom_command(TARGET rts-editor POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:rts-editor>
)

# Copy Qt files
IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	SET(QT_BIN_DIR ${Qt5Core_DIR}/../../../bin)
	ADD_CUSTOM_COMMAND(TARGET rts-editor POST_BUILD
	  COMMAND ${CMAKE_COMMAND} -E copy ${QT_BIN_DIR}/Qt5Widgetsd.dll $<TARGET_FILE_DIR:rts-editor>
	  COMMAND ${CMAKE_COMMAND} -E copy ${QT_BIN_DIR}/Qt5Guid.dll $<TARGET_FILE_DIR:rts-editor>
	  COMMAND ${CMAKE_COMMAND} -E copy ${QT_BIN_DIR}/Qt5Cored.dll $<TARGET_FILE_DIR:rts-editor>
	  COMMAND ${CMAKE_COMMAND} -E copy ${QT_BIN_DIR}/icuin53.dll $<TARGET_FILE_DIR:rts-editor>
	  COMMAND ${CMAKE_COMMAND} -E copy ${QT_BIN_DIR}/icuuc53.dll $<TARGET_FILE_DIR:rts-editor>
	  COMMAND ${CMAKE_COMMAND} -E copy ${QT_BIN_DIR}/icudt53.dll $<TARGET_FILE_DIR:rts-editor>
	)
ENDIF()
