cmake_minimum_required(VERSION 3.10)
project(PIXEL-TRACER VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")
add_executable(PIXEL-TRACER ${SOURCES})

target_include_directories(PIXEL-TRACER PRIVATE header)