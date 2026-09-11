#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "DanceBehavior.h"
#include <iostream>

class RubberDuck : public Duck
{
public:
    RubberDuck()
        : Duck(Fly::NoWay(), Quack::Squeak(), ::Dance::Minuet())
    {
    }

    void Display() const override
    {
        std::cout << "I'm rubber duck" << std::endl;
    }

};

#endif