cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project("DESIGN_PATTERNS")

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(compile_options)

add_subdirectory(package)

if(BUILD_TESTING)
  enable_testing()
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
  )

  FetchContent_MakeAvailable(googletest)
  include(GoogleTest)
  include(CTest)
  add_subdirectory(test)
endif(BUILD_TESTING)
