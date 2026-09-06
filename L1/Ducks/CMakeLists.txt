cmake_minimum_required(VERSION 4.1)
project(Ducks)

set(CMAKE_CXX_STANDARD 23)

add_executable(Ducks main.cpp
        DuckFunctions.h
        Duck/DecoyDuck.h
        Duck/Duck.h
        Duck/MallarDuck.h
        Duck/ModelDuck.h
        Duck/RedheadDuck.h
        Duck/RubberDuck.h)
