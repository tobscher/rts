SET (engine_LIB engine)
FILE (GLOB_RECURSE engine_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (engine_LIBS glfw libglew_static ${Boost_LIBRARIES} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} ${OPENGL_LIBRARIES})

ADD_LIBRARY(
  ${engine_LIB}
  STATIC
  ${engine_SRCS}
)

TARGET_LINK_LIBRARIES(
  ${engine_LIB}
  ${engine_LIBS}
)

INSTALL(TARGETS ${engine_LIB} DESTINATION lib)
