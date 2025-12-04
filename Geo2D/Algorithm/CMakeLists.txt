set(MODULE_NAME Algorithm )

# DEFINE THE TARGET
set( LIBNAME Geo2D_${MODULE_NAME} )

set( HEADERS
  AlgoConvexHull.h
#Contour.imp.h
#BoundingBox.imp.h
#Circle.imp.h
#Geo2D.imp.h
#HalfLine.imp.h
#Line.imp.h
#LineSegment.imp.h
#Vector.imp.h
)

add_library( ${LIBNAME} SHARED
  AlgoConvexHull.cxx
)

# create a property to hold our headers
set_target_properties(${LIBNAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

# DEFINE SOME VARS THAT MIGHT BE USEFUL FOR SUBMODULES
#message("msg[${MODULE_NAME}]: for debug")

get_target_property(ALL_HEADERS ${LIBNAME} PUBLIC_HEADER)

target_include_directories(${LIBNAME}
  PUBLIC
  $<INSTALL_INTERFACE:include/Geo2D/${MODULE_NAME}>
  ${LARLITE_INC_DIRS}
  PRIVATE
  ${PROJECT_SOURCE_DIR}
  ${OpenCV_INCLUDE_DIRS}
  )
target_link_libraries(${LIBNAME} PUBLIC
  opencv_core
  opencv_imgproc
  Geo2D_Core
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})
ROOT_GENERATE_DICTIONARY(G__${LIBNAME} ${ALL_HEADERS} ${HEADERS} LINKDEF LinkDef.h)
target_sources( ${LIBNAME} PRIVATE G__${LIBNAME}.cxx )

# install libraries and headers
install(TARGETS ${LIBNAME}
  EXPORT Geo2D
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include/Geo2D/${MODULE_NAME})

# install files needed for dictionary use in CINT/CLING/PYTHON
install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/lib${LIBNAME}_rdict.pcm
  ${CMAKE_CURRENT_BINARY_DIR}/lib${LIBNAME}.rootmap
  DESTINATION lib  )
