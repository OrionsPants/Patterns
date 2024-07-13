add_executable(factory_test factory_test.cpp)

target_link_libraries(factory_test PRIVATE gtest_main dp::factory)

add_test(NAME factory_test COMMAND factory_test)

set_project_warnings(COMPILE_OPTIONS)
target_compile_options(factory_test PRIVATE ${COMPILE_OPTIONS})
