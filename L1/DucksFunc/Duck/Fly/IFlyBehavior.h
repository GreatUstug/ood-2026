#ifndef DUCKS_IFLYBEHAVIOR_H
#define DUCKS_IFLYBEHAVIOR_H
#include <memory>

struct IFlyBehavior
{
    virtual ~IFlyBehavior(){};
    virtual void Fly() = 0;
    virtual bool CanFly() const {return true;}
    virtual int GetFlightCount() const {return 0;}
};

#endif //DUCKS_IFLYBEHAVIOR_H