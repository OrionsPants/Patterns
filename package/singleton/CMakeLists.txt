add_library(singleton include/singleton.h src/singleton.cpp)

add_library(dp::singleton ALIAS singleton)

target_include_directories(singleton PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_project_warnings(COMPILE_OPTIONS)

target_compile_options(singleton PRIVATE ${COMPILE_OPTIONS})
