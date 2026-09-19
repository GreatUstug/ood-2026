//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_TEXT_H
#define FIGURES_TEXT_H
#include "IShape.h"

class Text : public IShape
{
public:
	Text(std::string color, double x, double y, double size, std::string text) : m_size(size), m_text(text)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	}
	virtual ~Text() = default;
	std::string GetInfo() const override {
		return "text " + m_color + " " +
			   std::to_string(m_x) + " " + std::to_string(m_y) + " " +
			   std::to_string(m_size) + " " + m_text;
	}
	void Draw(gfx::ICanvas& canvas) const override {
		canvas.SetColor(gfx::Color::Parse(m_color));
		canvas.DrawText(m_x, m_y, m_size, m_text);
	}
private:
	double m_size;
	std::string m_text;
};
#endif //FIGURES_TEXT_H