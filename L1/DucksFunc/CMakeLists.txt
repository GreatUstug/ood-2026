cmake_minimum_required(VERSION 4.1)
project(DucksFunc)

set(CMAKE_CXX_STANDARD 23)

add_executable(DucksFunc main.cpp
        DuckFunctions.h
        Duck/DecoyDuck.h
        Duck/Duck.h
        Duck/MallarDuck.h
        Duck/ModelDuck.h
        Duck/RedheadDuck.h
        Duck/RubberDuck.h
        Duck/Fly/FlyNoWay.h
        Duck/Fly/FlyWithWings.h
        Duck/Fly/IFlyBehavior.h
        Mocks/MockFlyBehavior.h
        Duck/FlyBehavior.h
        Duck/DanceBehavior.h
        Duck/QuackBehavior.h
)

