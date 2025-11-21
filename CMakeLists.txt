# Set the minimun version of CMake required
cmake_minimum_required(VERSION 3.23)

#Define the project
project(CleverEngine LANGUAGES CXX)

# Set the C++ standard to C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY"${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY"${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_executable(CleverEngine source/main.cpp)

set(LIBRARY_DIR "${PROJECT_SOURCE_DIR}/library")

add_subdirectory(${LIBRARY_DIR}/SDL3)

target_link_libraries(CleverEngine SDL3::SDL3)