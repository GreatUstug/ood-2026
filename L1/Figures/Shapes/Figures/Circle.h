//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_CIRCLE_H
#define FIGURES_CIRCLE_H
#include "IShape.h"

class Circle : public IShape
{
	public:
	Circle(int number, int x, int y, double radius) : m_radius(radius)
	{
		m_number = number;
		m_x = x;
		m_y = y;
	}
	virtual ~Circle() = default;
	private:
	double m_radius;
};

#endif //FIGURES_CIRCLE_H