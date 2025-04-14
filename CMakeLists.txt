cmake_minimum_required(VERSION 3.10)
project(Geo2D VERSION 1.0.0)

#---Install location by default is in the build directory
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "${CMAKE_BUILD_DIR}" FORCE )
endif()

#---Module directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

## Dependencies

#---CERN ROOT
find_package(ROOT CONFIG REQUIRED)
# we set the compiler version based on the one used for ROOT
execute_process(
    COMMAND bash "-c" "root-config --features"
    OUTPUT_VARIABLE TEST_ROOT_CXX_STANDARD )
message( STATUS "Root features: ${TEST_ROOT_CXX_STANDARD}")
if (${TEST_ROOT_CXX_STANDARD} MATCHES "cxx17")
  message( STATUS "Using cxx17")
  set(CMAKE_CXX_STANDARD 17)
elseif (${TEST_ROOT_CXX_STANDARD} MATCHES "cxx14")
  message( STATUS "Using cxx14")
  set(CMAKE_CXX_STANDARD "14")
else ()
  message( STATUS "Using cxx11")  
  set(CMAKE_CXX_STANDARD "11")
endif()
link_libraries( ${ROOT_LIBRARIES} )

#---PYTHON
if (USE_PYTHON3)
  message(STATUS "Using Python 3")
  find_package( PythonInterp 3 REQUIRED )
  find_package( PythonLibs 3 REQUIRED )
  # warning gross hack
  execute_process( COMMAND python3 -c "import numpy; print(numpy.get_include())" OUTPUT_VARIABLE NUMPY_INCLUDES OUTPUT_STRIP_TRAILING_WHITESPACE )
  #message(${NUMPY_INCLUDES})
  set(GEO2D_USE_PYTHON 1)
  set(GEO2D_PYTHON_VERSION 3)
elseif(USE_PYTHON2)
  message(STATUS "Using Python 2")  
  find_package( PythonInterp 2.7 REQUIRED )
  find_package( PythonLibs 2.7 REQUIRED )
  set(GEO2D_USE_PYTHON 1)
  set(GEO2D_PYTHON_VERSION 2)
else()
  set(GEO2D_USE_PYTHON 0)
endif()

## Git Submodules

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  # Update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
  endif()
endif()

## Setup

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

#---Define Variables for subdirectory cmakelists
set(GEO2D_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")


#---Add base of source
add_subdirectory(Geo2D)

#---Configuration export
include(CMakePackageConfigHelpers)
set(GEO2D_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/include")
set(GEO2D_LIBRARY_DIR "${CMAKE_INSTALL_PREFIX}/lib")
set(TARGETS_EXPORT_NAME "Geo2DTargets")
configure_package_config_file("cmake/Config.cmake.in"
  "${CMAKE_BINARY_DIR}/cmake/Geo2DConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Geo2D"
  PATH_VARS GEO2D_INCLUDE_DIR GEO2D_LIBRARY_DIR GEO2D_BASE_DIR GEO2D_USE_PYTHON GEO2D_PYTHON_VERSION)
write_basic_package_version_file("${CMAKE_BINARY_DIR}/cmake/Geo2DConfigVersion.cmake"
  COMPATIBILITY SameMajorVersion)


## Export Targets

#---Create info to include Geo2D in other cmake files
install(EXPORT Geo2D
        FILE Geo2DTargets.cmake
        DESTINATION "${CMAKE_BINARY_DIR}/installed/lib/cmake/Geo2D")

#---Create info to include Geo2D in other cmake files
install(FILES "${CMAKE_BINARY_DIR}/cmake/Geo2DConfig.cmake"
  "${CMAKE_BINARY_DIR}/cmake/Geo2DConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Geo2D")
