cmake_minimum_required(VERSION 4.1)
project(Figures)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)
add_subdirectory(Tests)

add_executable(Figures main.cpp
        ShapesCommandHandler.h
        Shapes/Picture.h
        Shapes/Figures/Shape.h
        ShapeParams.h)