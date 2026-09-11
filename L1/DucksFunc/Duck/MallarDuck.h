#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Duck.h"
#include "DanceBehavior.h"
#include "Fly/FlyWithWings.h"
#include "QuackBehavior.h"

class MallardDuck : public Duck
{
public:
    MallardDuck()
        : Duck(Fly::WithWings(), Quack::Normal(), Dance::Waltz())
    {
    }

    void Display() const override
    {
        std::cout << "I'm mallard duck" << std::endl;
    }
};

#endif