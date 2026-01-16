// cmake_minimum_required(VERSION 3.15)
// project(PixelTracer)

// set(CMAKE_CXX_STANDARD 17)
// set(CMAKE_CXX_STANDARD_REQUIRED ON)

// # Inclure tous les cpp
// set(SOURCES
//     src/Main.cpp
//     src/Area.cpp
//     src/Line.cpp
//     src/Point.cpp
//     src/Pixel.cpp

//     src/Circle.cpp
//     src/Polygon.cpp
//     src/Shape.cpp
  
// )

// add_executable(PixelTracer ${SOURCES})

cmake_minimum_required(VERSION 3.10)
project(PixelTracer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(pixel_tracer
src/Main.cpp
src/Point.cpp
src/Shape.cpp
src/Line.cpp
src/Circle.cpp
src/Square.cpp
src/Rectangle.cpp
src/Polygon.cpp
src/Pixel.cpp
src/Area.cpp
src/Command.cpp
src/Layer.cpp
src/Curve.cpp
)

