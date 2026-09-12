//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_PICTURE_H
#define FIGURES_PICTURE_H
#include "Figures/Circle.h"

#include <unordered_map>
#include "Figures/IShape.h"

#include <map>
#include <memory>
#include <string>

class Picture
{
	public:
	Picture() = default;
	void AddShape(const ShapeParams& params)
	{
		auto shape = CreateShape(params);
		m_shapes[params.id] = std::move(shape);
	}
	std::unique_ptr<IShape> CreateShape(const ShapeParams& params)
	{
		// switch (params.type)
		// {
		// 	case "circle":return std::make_unique<Circle>();
		// }
		if (m_shapes.find(params.id) != m_shapes.end())
		{
			throw std::exception();
		}
		if (params.type == "circle")
		{
			double radius = std::stod(params.params[0]);
			return std::make_unique<Circle>(params.color, params.x, params.y, radius);
		}

	}
	private:
		std::map<std::string, std::unique_ptr<IShape>> m_shapes;
};

#endif //FIGURES_PICTURE_H