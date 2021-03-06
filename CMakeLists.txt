# Tobias Haar. Copyright (C) 2015. MIT-License.

#
# Project Properties
#
CMAKE_MINIMUM_REQUIRED (VERSION 3.0.2)
PROJECT (rts)
SET(BUILD_SHARED_LIBS OFF CACHE BOOL "")
SET (APPLICATION_NAME "rts")
SET (APPLICATION_CODENAME "${PROJECT_NAME}")
SET (APPLICATION_COPYRIGHT_YEARS "2014")
SET (APPLICATION_VERSION_MAJOR 0)
SET (APPLICATION_VERSION_MINOR 0)
SET (APPLICATION_VERSION_PATCH 1)
SET (APPLICATION_VERSION_TYPE SNAPSHOT)
SET (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}-${APPLICATION_VERSION_TYPE}")
SET (APPLICATION_VENDOR_ID "tobscher")
SET (APPLICATION_VENDOR_NAME "Tobias Haar")
SET (APPLICATION_VENDOR_URL "github.com/tobscher")
SET (APPLICATION_ID "${APPLICATION_VENDOR_ID}.${PROJECT_NAME}")
SET(BUILD_UNIT_TESTS OFF CACHE BOOL "")
SET(BUILD_BULLET3 OFF CACHE BOOL "")
SET(BUILD_CPU_DEMOS OFF CACHE BOOL "")
SET(BUILD_BULLET2_DEMOS OFF CACHE BOOL "")
SET(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "")
SET(BUILD_EXTRAS OFF CACHE BOOL "")
SET(PHYSFS_ARCHIVE_ZIP OFF CACHE BOOL "")

# Activate C++ 11
IF(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ENDIF()

#
# Debugging Options
#
SET (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release

#
# Project Output Paths
#
SET (MAINFOLDER ${PROJECT_SOURCE_DIR})
SET (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
SET (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")

#
# Project Search Paths
#
LIST (APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}")
LIST (APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/tools")
LIST (APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/thirdparty")
SET (CMAKE_MODULE_PATH "${MAINFOLDER}/tools/share/cmake")
INCLUDE_DIRECTORIES("${MAINFOLDER}/include")
LINK_DIRECTORIES(${MAINFOLDER}/lib)

# Include overrides
INCLUDE(c_flag_overrides)
INCLUDE(cxx_flag_overrides)

IF(MSVC)
  MESSAGE("Overriding existing compiler flags")
  set(CompilerFlags
    CMAKE_CXX_FLAGS
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_C_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_RELEASE
  )
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  endforeach()
ENDIF(MSVC)

# Find pkg-config
FIND_PACKAGE(PkgConfig)

#
# Locate Project Prerequisites
#

# Building only the GLFW lib
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "")
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "")
SET(GLFW_INSTALL OFF CACHE BOOL "")
ADD_SUBDIRECTORY(thirdparty/glfw)
INCLUDE_DIRECTORIES(thirdparty/glfw/include)

# GLEW
OPTION(glew-cmake_BUILD_SHARED OFF)
ADD_SUBDIRECTORY(thirdparty/glew)
INCLUDE_DIRECTORIES(thirdparty/glew/include)

# GLM
SET(GLM_SOURCE_DIR "thirdparty/glm")
INCLUDE_DIRECTORIES(${GLM_SOURCE_DIR})

# SOIL
SET(SOIL_BUILD_TESTS OFF CACHE BOOL "")
ADD_SUBDIRECTORY(thirdparty/SOIL2)
INCLUDE_DIRECTORIES(thirdparty/SOIL2/src/SOIL2)

# Bullet
ADD_SUBDIRECTORY(thirdparty/bullet)
INCLUDE_DIRECTORIES(thirdparty/bullet/src)

# spdlog
INCLUDE_DIRECTORIES(thirdparty/spdlog/include)

# googletest
ADD_SUBDIRECTORY(thirdparty/googletest)

# physfs
OPTION(PHYSFS_BUILD_SHARED FALSE)
OPTION(PHYSFS_BUILD_DOCS OFF)
SET(PHYSFS_BUILD_TEST OFF CACHE BOOL "" FORCE)
OPTION(PHYSFS_BUILD_DIST OFF)
ADD_SUBDIRECTORY(thirdparty/physfs)
INCLUDE_DIRECTORIES(thirdparty/physfs)

# pugixml
ADD_SUBDIRECTORY(thirdparty/pugixml/scripts)
INCLUDE_DIRECTORIES(thirdparty/pugixml/src)

# Recast
ADD_SUBDIRECTORY(thirdparty/recastnavigation/Recast)
INCLUDE_DIRECTORIES(thirdparty/recastnavigation/Recast/Include)

# Detour
ADD_SUBDIRECTORY(thirdparty/recastnavigation/Detour)
INCLUDE_DIRECTORIES(thirdparty/recastnavigation/Detour/Include)

# Assimp
OPTION(ASSIMP_BUILD_TESTS FALSE)
ADD_SUBDIRECTORY(thirdparty/assimp)
INCLUDE_DIRECTORIES(thirdparty/assimp/include)

#
# Configure Files
#
FILE (GLOB_RECURSE CONFIGINPUTS1 include/*.in.h.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS2 include/*.h.in.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS3 src/*.in.h.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS4 src/*.h.in.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS5 test/*.in.h.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS6 test/*.h.in.cmake)
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS1}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS2}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS3}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS4}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS5}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS6}")
FOREACH (CONFIGINPUT ${CONFIGINPUTS})
    STRING (REPLACE ".in.h.cmake" ".h" CONFIGOUTPUT1 "${CONFIGINPUT}")
    STRING (REPLACE ".h.in.cmake" ".h" CONFIGOUTPUT2 "${CONFIGOUTPUT1}")
    CONFIGURE_FILE ("${CONFIGINPUT}" "${CONFIGOUTPUT2}")
ENDFOREACH (CONFIGINPUT ${CONFIGINPUTS})

# shaders
FILE (GLOB_RECURSE shader_SRCS shaders/*.frag shaders/*.vert)

# textures
FILE (GLOB_RECURSE texture_SRCS textures/*.jpg textures/*.png textures/*.dds)

# fonts
FILE (GLOB_RECURSE font_SRCS fonts/*.PNG fonts/*.xml)

#
# Add Build Targets
#
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)

#
# Add Install Targets
#
IF (EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")
    INSTALL(DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}" DESTINATION "include")
ENDIF (EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")

#
# Add Documentation Targets
#
INCLUDE (DocumentationTargets)

FILE (GLOB_RECURSE clion_all_headers ${CMAKE_SOURCE_DIR}/include/*.h)
ADD_CUSTOM_TARGET(all_clion
    SOURCES ${clion_all_headers}
)
