cmake_minimum_required(VERSION 4.0)

project(CleverEngine LANGUAGES CXX)

find_program(CCACHE_PROGRAM ccache)

if (CCACHE_PROGRAM)
    message(STATUS "Using ccache:    ${CCACHE_PROGRAM}")
    set(CMAKE_C_COMPILER_LAUNCHER   "${CCACHE_PROGRAM}")
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif ()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_executable(CleverEngine source/main.cpp)


set(SDLTTF_VENDORED ON)
set(LIBRARY_DIR "${PROJECT_SOURCE_DIR}/library")
add_subdirectory(${LIBRARY_DIR}/SDL3)
add_subdirectory(${LIBRARY_DIR}/SDL3_image)
add_subdirectory(${LIBRARY_DIR}/SDL3_ttf)


target_link_libraries(CleverEngine 
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)