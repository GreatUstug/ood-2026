//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_LINE_H
#define FIGURES_LINE_H
#include "IShape.h"

#include <string>

class Line : public IShape
{
public:
	Line(std::string color, double x, double y, double yEnd, double xEnd) : m_xEnd(xEnd), m_yEnd(yEnd)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	}
	virtual ~Line() = default;
	std::string GetInfo() const override {
		return "line " + m_color + " " +
			   std::to_string(m_x) + " " + std::to_string(m_y) + " " +
			   std::to_string(m_xEnd) + " " + std::to_string(m_yEnd);
	}
private:
	double m_xEnd;
	double m_yEnd;
};
#endif //FIGURES_LINE_H