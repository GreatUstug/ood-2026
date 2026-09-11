#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "DanceBehavior.h"
class ModelDuck : public Duck
{
public:
    ModelDuck()
        : Duck(Fly::NoWay(), Quack::Normal(), Dance::NoWay())
    {
    }

    void Display() const override
    {
        std::cout << "I'm model duck" << std::endl;
    }

};

#endif