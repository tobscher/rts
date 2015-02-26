FILE (GLOB_RECURSE engine_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (engine_LIBS glfw ${GLFW_LIBRARIES} ${Boost_LIBRARIES} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

ADD_LIBRARY(
  engine
  STATIC
  ${engine_SRCS}
)

TARGET_LINK_LIBRARIES(
  engine
  ${engine_LIBS}
)
