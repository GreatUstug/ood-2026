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
private:
	double m_size;
	std::string m_text;
};
#endif //FIGURES_TEXT_H