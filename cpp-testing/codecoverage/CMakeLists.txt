cmake_minimum_required(VERSION 3.11)
project(lib_coverage_testing CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

add_executable(lib_test
    lib_test.cpp
)

add_custom_target(coverage
    COMMAND lib_test
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${CMAKE_BINARY_DIR}/CMakeFiles/lib_test.dir
)