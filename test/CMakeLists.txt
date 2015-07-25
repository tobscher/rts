FILE (GLOB_RECURSE test_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (
  test_LIBS
  engine
  rts
  glfw
  ${GLFW_LIBRARIES}
  BulletDynamics
  BulletCollision
  LinearMath
  libglew_static
  ${ZLIB_LIBRARIES}
  physfs-static
  gtest_main
)
SET (test_BIN ${PROJECT_NAME}-unittests)

ADD_EXECUTABLE(${test_BIN} ${test_SRCS} ${game_SRCS})
TARGET_LINK_LIBRARIES(
  ${test_BIN}
  ${test_LIBS}
)

INCLUDE_DIRECTORIES(
  ${gtest_SOURCE_DIR}/include
  "${MAINFOLDER}/src"
)

ADD_CUSTOM_TARGET(check ALL ${test_BIN} DEPENDS ${test_BIN} COMMENT "Executing unit tests..." VERBATIM SOURCES ${test_SRCS})
