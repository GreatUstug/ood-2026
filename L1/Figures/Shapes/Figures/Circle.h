//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_CIRCLE_H
#define FIGURES_CIRCLE_H
#include "IShape.h"

class Circle : public IShape
{
	public:
	Circle(std::string color, double x, double y, double radius) : m_radius(radius)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	}
	virtual ~Circle() = default;
	private:
	double m_radius;
};

#endif //FIGURES_CIRCLE_H