#ifndef DUCK_H
#define DUCK_H

#include "FlyBehavior.h"
#include "QuackBehavior.h"

#include <cassert>
#include <iostream>
#include <memory>

#include "DanceBehavior.h"

#include <functional>

using Behavior = std::function<void()>;

class Duck
{
public:
    Duck(
    	Behavior fly,
    	Behavior quack,
    	Behavior dance,
    	Behavior display
    	)
		: m_flyBehavior(std::move(fly))
		, m_quackBehavior(std::move(quack))
		, m_danceBehavior(std::move(dance))
		, m_displayBehavior(std::move(display))
    {
        assert(m_quackBehavior);
        assert(m_danceBehavior);
    	// TODO: почему ассерты и полчему сеттер именно в таком виде
        assert(m_flyBehavior);
    }

    void Quack() const
    {
        m_quackBehavior();
    }

    void Swim() const
    {
        std::cout << "I'm swimming" << std::endl;
    }

    void Fly()
    {
    	m_flyBehavior();
     //    m_flyBehavior->Fly();
    	// PrintFlyCount();
    	// CheckAndQuack();
    }

    void Dance() const
    {
        m_danceBehavior();
    }

    void SetFlyBehavior(Behavior flyBehavior)
    {
        assert(flyBehavior);
        m_flyBehavior = std::move(flyBehavior);
    }

    void Display() const
    {
	    m_displayBehavior();
    };
    ~Duck() = default;

private:
	// void PrintFlyCount() const
	// {
	// 	std::cout << "Fly count: " << m_flyBehavior->GetFlightCount() << std::endl;
	// }
 //    void CheckAndQuack() const
 //    {
 //        int flightCount = m_flyBehavior->GetFlightCount();
 //        if (flightCount != 0 && flightCount % FLIGHT_DIVIDER == 0) {
 //            m_quackBehavior->Quack();
 //        }
 //    }
	Behavior m_displayBehavior;
    Behavior m_flyBehavior;
    Behavior m_quackBehavior;
    Behavior m_danceBehavior;
    const int FLIGHT_DIVIDER = 2;
};

#endif