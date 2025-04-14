set(MODULE_NAME PyUtil )

# DEFINE THE TARGET
set( LIBNAME Geo2D_${MODULE_NAME} )

set( HEADERS
  PyDraw.h
  PyFuncs.h
)

add_library( ${LIBNAME} SHARED
  PyDraw.cxx
  PyFuncs.cxx
)

# create a property to hold our headers
set_target_properties(${LIBNAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

# DEFINE SOME VARS THAT MIGHT BE USEFUL FOR SUBMODULES
#message("msg[${MODULE_NAME}]: for debug")
#message( "python libs: ${PYTHON_LIBRARIES}" )
  
get_target_property(ALL_HEADERS ${LIBNAME} PUBLIC_HEADER)

target_include_directories(${LIBNAME}
  PUBLIC
  $<INSTALL_INTERFACE:include/Geo2D/${MODULE_NAME}>
  ${LARLITE_INC_DIRS}
  ${PYTHON_INCLUDE_PATH}
  ${NUMPY_INCLUDES}
  ${OpenCV_INCLUDE_DIRS}
  PRIVATE
  ${PROJECT_SOURCE_DIR}
  )
target_link_libraries(${LIBNAME} PUBLIC
  opencv_core
  opencv_imgproc
  Geo2D_Core
  ${PYTHON_LIBRARIES}
  ${NUMPY_LIBRARIES}
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}
  ${OpenCV_INCLUDE_DIRS}
  ${PYTHON_INCLUDE_PATH}
  ${NUMPY_INCLUDES}  
)
ROOT_GENERATE_DICTIONARY(G__${LIBNAME}
  ${HEADERS}
  LINKDEF LinkDef.h
)
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
