PROJECT(optflow)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(CMAKE_VERBOSE_MAKEFILE ON)

ADD_DEFINITIONS(-Wall -O2 -frounding-math)

OPTION(WITH_BOOST_PROGRAM_OPTIONS "compile with Boost.Program_options (enables command-line interface)" ON)
OPTION(WITH_CGAL "compile with CGAL (enables sparse motion field and triangulation support)" ON)
OPTION(WITH_OPENCV "compile with OpenCV (enables OpenCV motion extraction algorithms)" ON)
OPTION(WITH_MATLAB "compile with MATLAB interface" OFF)

IF(WITH_CGAL)
  ADD_DEFINITIONS(-DWITH_CGAL)
ENDIF()

IF(WITH_OPENCV)
  ADD_DEFINITIONS(-DWITH_OPENCV)
ENDIF()

ADD_SUBDIRECTORY(lib)
IF(WITH_BOOST_PROGRAM_OPTIONS)
  ADD_DEFINITIONS(-DWITH_BOOST_PROGRAM_OPTIONS)
  ADD_SUBDIRECTORY(bin)
ENDIF()

IF(WITH_MATLAB)
  ADD_SUBDIRECTORY(matlab)
ENDIF()
