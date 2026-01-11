cmake_minimum_required(VERSION 3.15)
project(PixelTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclure tous les cpp
set(SOURCES
    src/Main.cpp
    src/Area.cpp
    src/Line.cpp
    src/Point.cpp
    src/Pixel.cpp

    src/Circle.cpp
    src/Polygon.cpp
    src/Shape.cpp
  
)

add_executable(PixelTracer ${SOURCES})
