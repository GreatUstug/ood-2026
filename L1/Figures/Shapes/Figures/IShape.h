//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_SHAPE_H
#define FIGURES_SHAPE_H
#include "../../ShapeParams.h"

#include <string>
#include <vector>

class IShape
{
	public:
		virtual ~IShape() = default;
	protected:
		std::string m_color;
		double m_x;
		double m_y;
};

#endif //FIGURES_SHAPE_H