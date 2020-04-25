cmake_minimum_required(VERSION 3.11)
project(lib_coverage_testing CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

add_executable(lib_test
    lib_test.cpp
)

add_custom_target(coverage_gcov
    COMMAND lib_test
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${CMAKE_BINARY_DIR}/CMakeFiles/lib_test.dir
)

# When building with gcc version 9+ you need very recent version of lcov (see https://github.com/linux-test-project/lcov/issues/58)
# GCC 8 is supported with (currently) latest lcov version 1.14
add_custom_target(coverage_lcov
    COMMAND lib_test
    COMMAND lcov --capture --directory . --output-file lib_test_coverage.info
    COMMAND genhtml lib_test_coverage.info
)
