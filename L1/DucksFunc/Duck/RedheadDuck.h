#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "DanceBehavior.h"

class RedheadDuck : public Duck
{
public:
    RedheadDuck()
        : Duck(Fly::WithWings(), Quack::Normal(), Dance::Minuet())
    {
    }

    void Display() const override
    {
        std::cout << "I'm redhead duck" << std::endl;
    }
};

#endif