
INCLUDE_DIRECTORIES(../lib)

ADD_EXECUTABLE(extractmotion extractmotion.cpp)
ADD_EXECUTABLE(extrapolate extrapolate.cpp)
ADD_EXECUTABLE(morph morph.cpp)

SET(LIBS "boost_program_options" "optflow")

IF(WITH_CGAL)
  SET(LIBS ${LIBS} "CGAL")
ENDIF()

IF(WITH_OPENCV)
  SET(LIBS ${LIBS} "opencv_core")
  SET(LIBS ${LIBS} "opencv_video")
ENDIF()

TARGET_LINK_LIBRARIES(extractmotion ${LIBS})
TARGET_LINK_LIBRARIES(extrapolate ${LIBS})
TARGET_LINK_LIBRARIES(morph ${LIBS})

INSTALL(TARGETS extractmotion extrapolate morph DESTINATION bin)
