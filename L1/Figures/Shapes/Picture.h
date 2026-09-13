//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_PICTURE_H
#define FIGURES_PICTURE_H
#include "Figures/Circle.h"

#include <unordered_map>
#include "Figures/IShape.h"
#include "Figures/Line.h"
#include "Figures/Rectangle.h"
#include "Figures/Text.h"
#include "Figures/Triangle.h"

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
		if (m_shapes.find(params.id) != m_shapes.end())
		{
			throw std::exception();
		}
		switch (params.type)
		{
		case ShapeType::CIRCLE: {
			double radius = std::stod(params.params[0]);
			return std::make_unique<Circle>(params.color, params.x, params.y, radius);
		}
		case ShapeType::RECTANGLE: {
			double w = std::stod(params.params[0]);
			double h = std::stod(params.params[1]);
			return std::make_unique<Rectangle>(params.color, params.x, params.y, w, h);
		}
		case ShapeType::TRIANGLE: {
			double x2 = std::stod(params.params[0]);
			double y2 = std::stod(params.params[1]);
			double x3 = std::stod(params.params[2]);
			double y3 = std::stod(params.params[3]);
			return std::make_unique<Triangle>(params.color, params.x, params.y, x2, y2, x3, y3);
		}
		case ShapeType::LINE: {
			double xEnd = std::stod(params.params[0]);
			double yEnd = std::stod(params.params[1]);
			return std::make_unique<Line>(params.color, params.x, params.y, xEnd, yEnd);
		}
		case ShapeType::TEXT: {
			double size = std::stod(params.params[0]);
			std::string text = params.params[1];
			return std::make_unique<Text>(params.color, params.x, params.y, size, text);
		}
		}
	}
	std::string ListOneShape(const std::string& id)
	{
		return m_shapes[id]->GetInfo();
	};
	std::vector<std::string> ListAllShapes()
	{
		std::vector<std::string> list;
		for (auto& it : m_shapes)
		{
			list.push_back(m_shapes[it.first]->GetInfo());
		}
		return list;
	};
	void EditShapeColor(const std::string& id, const std::string& color)
	{
		m_shapes[id]->SetColor(color);
	}
	private:
		std::map<std::string, std::unique_ptr<IShape>> m_shapes;
};

#endif //FIGURES_PICTURE_H