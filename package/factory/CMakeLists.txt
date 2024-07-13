add_library(factory include/factory.h src/factory.cpp)

add_library(dp::factory ALIAS factory)

target_include_directories(factory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_project_warnings(COMPILE_OPTIONS)

target_compile_options(factory PRIVATE ${COMPILE_OPTIONS})
