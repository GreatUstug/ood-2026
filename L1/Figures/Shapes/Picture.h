//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_PICTURE_H
#define FIGURES_PICTURE_H
#include <unordered_map>
#include "Figures/Shape.h"

#include <string>

class Picture
{
	public:
	Picture() = default;
	void AddShape(const ShapeParams& params)
	{
		// m_shapes[params.id] = std::move(shape);
	}
	private:
		std::unordered_map<std::string, Shape> m_shapes;
};

#endif //FIGURES_PICTURE_H