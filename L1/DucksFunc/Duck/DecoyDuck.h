//
// Created by maxim on 06.09.2026.
//

#ifndef DUCKS_DECOYDUCK_H
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "DanceBehavior.h"
#include <iostream>
#include <memory>

class DecoyDuck : public Duck
{
public:
    DecoyDuck()
        : Duck(Fly::NoWay(), Quack::Mute(), Dance::NoWay())
    {
    }

    void Display() const override
    {
        std::cout << "I'm decoy duck" << std::endl;
    }

};
#define DUCKS_DECOYDUCK_H

#endif //DUCKS_DECOYDUCK_H