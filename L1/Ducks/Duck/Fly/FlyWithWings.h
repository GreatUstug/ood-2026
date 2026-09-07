#ifndef DUCKS_FLYWITHWINGS_H
#define DUCKS_FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
    void Fly() override
    {
        m_flightCount++;
        std::cout << "I'm flying with wings!!" << std::endl;
    }
    int GetFlightCount() const override
    {
        return m_flightCount;
    }
private:
    int m_flightCount = 0;
};

#endif //DUCKS_FLYWITHWINGS_H