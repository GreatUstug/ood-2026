//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_TRIANGLE_H
#define FIGURES_TRIANGLE_H
#include "IShape.h"

class Triangle : public IShape
{
public:
	Triangle(std::string color, double x, double y, double x2, double y2, double x3, double y3) : m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	}
	virtual ~Triangle() = default;
private:
	double m_x2;
	double m_y2;
	double m_x3;
	double m_y3;
};
#endif //FIGURES_TRIANGLE_H