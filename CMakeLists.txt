cmake_minimum_required(VERSION 3.20)
project(test_nanobind)


find_package(Python 3.8 COMPONENTS Interpreter Development.Module REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Detect the installed nanobind package and import it into CMake
execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR)
list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
find_package(nanobind CONFIG REQUIRED)


find_package(NGSolve CONFIG REQUIRED
  HINTS /usr $ENV{NETGENDIR}/.. /tmp/inst/usr /opt/netgen/ /Applications/Netgen.app/Contents/Resources/CMake C:/netgen
)

# include_directories(${NGSOLVE_INCLUDE_DIRS})
include_directories(/Applications/Netgen.app/Contents/Resources/include)
link_directories(/Applications/Netgen.app/Contents/MacOS)

link_libraries (ngbla)
link_libraries (ngcomp)

nanobind_add_module(bla nb_bla.cpp)
nanobind_add_module(comp nb_comp.cpp)




