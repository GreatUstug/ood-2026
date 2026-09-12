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
		int m_number;
		int m_x;
		int m_y;
};

#endif //FIGURES_SHAPE_H