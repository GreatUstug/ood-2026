cmake_minimum_required(VERSION 4.1)
project(DucksFunc)

set(CMAKE_CXX_STANDARD 23)

add_executable(DucksFunc main.cpp
        DuckFunctions.h
        Duck/Fly/FlyNoWay.h
        Duck/Fly/FlyWithWings.h
        Duck/Fly/IFlyBehavior.h
)

