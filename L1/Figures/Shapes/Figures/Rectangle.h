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
	Rectangle(std::string color, double x, double y, double width, double height) : m_width(width), m_height(height)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	}
	virtual ~Rectangle() = default;
	std::string GetInfo() const override {
		return "Rectangle at (" + std::to_string(m_x) + ", " + std::to_string(m_y) +
			   ") w=" + std::to_string(m_width) + " h=" + std::to_string(m_height);
	}
private:
	double m_width;
	double m_height;
};
#endif //FIGURES_RECTANGLE_H