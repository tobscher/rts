FILE (GLOB_RECURSE test_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (test_LIBS engine glfw ${GLFW_LIBRARIES} libglew_static ${ZLIB_LIBRARIES} physfs-static ${Boost_LIBRARIES} gtest_main)
SET (test_BIN ${PROJECT_NAME}-unittests)

ADD_EXECUTABLE(${test_BIN} ${test_SRCS})
TARGET_LINK_LIBRARIES(
  ${test_BIN}
  ${test_LIBS}
)

INCLUDE_DIRECTORIES(
  ${gtest_SOURCE_DIR}/include
  "${MAINFOLDER}/src"
)

ADD_CUSTOM_TARGET(check ALL ${test_BIN} DEPENDS ${test_BIN} COMMENT "Executing unit tests..." VERBATIM SOURCES ${test_SRCS})
