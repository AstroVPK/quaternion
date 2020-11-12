cmake_minimum_required(VERSION 3.10)

# set the project name
project(Quaternion  VERSION 0.0.1)

# set some directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/include")

# add the executable
add_executable(test ${PROJECT_SOURCE_DIR}/src/test.cpp)
