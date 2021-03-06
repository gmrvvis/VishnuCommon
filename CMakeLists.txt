﻿# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   Vishnu Common
#   2018-2019 (c) GMRV/URJC
#   Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
#   http://gmrv.es/gmrvvis/
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

cmake_minimum_required( VERSION 3.1 )
set( PROJECT_VERSION_MAJOR "1" )
set( PROJECT_VERSION_MINOR "4" )
set( PROJECT_VERSION_PATCH "0" )
set( PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} )
project( VishnuCommon VERSION ${PROJECT_VERSION} )
set( VishnuCommon_VERSION_ABI 5 )

# Disable in source building
if( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" )
  message( FATAL "no in source building allowed." )
endif( )

list( APPEND CMAKE_MODULE_PATH
  ${PROJECT_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/common 
)

# Default build type is Debug
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug )
endif( NOT CMAKE_BUILD_TYPE )

if ( CMAKE_BUILD_TYPE MATCHES "Debug" )
  add_definitions( -DDEBUG )
endif( )

include( GitExternal )

set( VISHNUCOMMON_DESCRIPTION "Vishnu Common" )
set( VISHNUCOMMON_MAINTAINER "Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>")
set( VISHNUCOMMON_LICENSE "MIT" )
set( COMMON_PROJECT_DOMAIN gmrv.es )

# Allow warnings
# set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w" )

include( Common )

common_find_package( Qt5Core SYSTEM REQUIRED )
common_find_package( Qt5Widgets SYSTEM REQUIRED )

common_find_package_post( )

list( APPEND VISHNUCOMMON_DEPENDENT_LIBRARIES 
  Qt5::Core
  Qt5::Gui 
  Qt5::Widgets
)

add_subdirectory( vishnucommon )
add_subdirectory( examples )

set( DOXYGEN_MAINPAGE_MD README.md )
set( DOXYGEN_EXTRA_INPUT ${PROJECT_SOURCE_DIR}/README.md )
include( DoxygenRule )

include( CPackConfig )
