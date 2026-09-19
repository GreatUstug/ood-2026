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
	std::string GetInfo() const override {
		return "triangle " + m_color + " " +
			   std::to_string(m_x) + " " + std::to_string(m_y) + " " +
			   std::to_string(m_x2) + " " + std::to_string(m_y2) + " " +
			   std::to_string(m_x3) + " " + std::to_string(m_y3);
	}
	void Draw(gfx::ICanvas& canvas) const override {
		canvas.SetColor(gfx::Color::Parse(m_color));

		canvas.MoveTo(m_x, m_y);
		canvas.LineTo(m_x2, m_y2);
		canvas.LineTo(m_x3, m_y3);
		canvas.LineTo(m_x, m_y);
	}
	virtual ~Triangle() = default;
private:
	double m_x2;
	double m_y2;
	double m_x3;
	double m_y3;
};
#endif //FIGURES_TRIANGLE_H