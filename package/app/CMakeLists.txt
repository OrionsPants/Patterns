add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE gtest_main dp::factory)

set_project_warnings(COMPILE_OPTIONS)
target_compile_options(main PRIVATE ${COMPILE_OPTIONS})
