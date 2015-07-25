SET (rts_LIB rts)
FILE (GLOB_RECURSE rts_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (rts_LIBS engine glfw libglew_static SOIL BulletDynamics BulletCollision LinearMath ${ZLIB_LIBRARY} physfs-static ${Log4Cxx_LIBRARIES})

ADD_LIBRARY(
  ${rts_LIB}
  STATIC
  ${rts_SRCS}
)

TARGET_LINK_LIBRARIES(
  ${rts_LIB}
  ${rts_LIBS}
)

INSTALL(TARGETS ${rts_LIB} DESTINATION lib)
