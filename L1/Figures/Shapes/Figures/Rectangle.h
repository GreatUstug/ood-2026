//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_RECTANGLE_H
#define FIGURES_RECTANGLE_H
#include "IShape.h"

#include <string>

class Rectangle : public IShape
{
public:
	Rectangle(std::string color, double x, double y, double width, double height) : m_xEnd(width), m_yEnd(height)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	}
	virtual ~Rectangle() = default;
private:
	double m_xEnd;
	double m_yEnd;
};
#endif //FIGURES_RECTANGLE_H