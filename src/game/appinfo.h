// Tobias Haar. Copyright (C) 2014. MIT-License.
#ifndef HEADER_SRC_APPINFO_H_INCLUDED
#define HEADER_SRC_APPINFO_H_INCLUDED

#include <boost/preprocessor/stringize.hpp>

/*
 * AUTO-GENERATION WARNING:
 *     This file has been automatically generated from "appinfo.h.in.cmake".
 *     DO NOT edit this file, as any changes will be automatically discarded.
 */
 
#define APPLICATION_NAME               "rts"
#define APPLICATION_CODENAME           "rts"
#define APPLICATION_COPYRIGHT_YEARS    "2014"
/* #undef APPLICATION_VERSION_MAJOR */
/* #undef APPLICATION_VERSION_MINOR */
#define APPLICATION_VERSION_PATCH      1
#define APPLICATION_VERSION_TYPE       "SNAPSHOT"
#define APPLICATION_VERSION_STRING     "0.0.1-SNAPSHOT"
#define APPLICATION_VENDOR_ID          "tobscher"
#define APPLICATION_VENDOR_NAME        "Tobias Haar"
#define APPLICATION_VENDOR_URL         "github.com/tobscher"
#define APPLICATION_ID                 "tobscher"

#ifndef APPLICATION_NAME
#   error "Please specify the application name in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_CODENAME
#   error "Please specify the application codename in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_COPYRIGHT_YEARS
#   error "Please specify the application copyright years (years during which this application was created, edited, or modified) in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_VERSION_MAJOR
#   define APPLICATION_VERSOIN_MAJOR 0
#endif

#ifndef APPLICATION_VERSION_MINOR
#   define APPLICATION_VERSION_MINOR 0
#endif

#ifndef APPLICATION_VERSION_PATCH
#   define APPLICATION_VERSION_PATCH 0
#endif

#ifndef APPLICATION_VERSION_TYPE
#   define APPLICATION_VERSION_TYPE "SNAPSHOT"
#endif

#ifndef APPLICATION_VERSION_STRING
#   define APPLICATION_VERSION_STRING BOOST_PP_STRINGIZE(APPLICATION_VERSION_MAJOR) "." BOOST_PP_STRINGIZE(APPLICATION_VERSION_MINOR) "." BOOST_PP_STRINGIZE(APPLICATION_VERSION_PATCH) "-" APPLICATION_VERSION_TYPE
#endif

#ifndef APPLICATION_VENDOR_ID
#   error "Please specify the application vendor id in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_VENDOR_NAME
#   error "Please specify the application vendor name in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_VENDOR_URL
#   error "Please specify the application vendor URL in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_ID
#   define APPLICATION_ID APPLICATION_VENDOR_ID "." APPLICATION_CODENAME
#endif

#endif
