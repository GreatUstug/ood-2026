//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_SHAPE_H
#define FIGURES_SHAPE_H
#include "../../ShapeParams.h"

#include <string>
#include <vector>

class Shape
{
	public:
		Shape(
			ShapeParams params
			)
		{
			m_number = params.num;
			m_type = params.type;
			m_id = params.id;
			m_x = params.x;
			m_y = params.y;
			m_params = params.params;
		};
		virtual ~Shape() = default;
	private:
		int m_number;
		std::string m_type;
		std::string m_id;
		int m_x;
		int m_y;
		std::vector<std::string> m_params;
};

#endif //FIGURES_SHAPE_H