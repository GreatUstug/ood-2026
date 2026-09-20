// Shapes/Picture.h
#pragma once
#include "IFigure.h"
#include "Figures/IShapeGeometry.h"
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"
#include "Figures/Line.h"
#include "Figures/Text.h"
#include "../ShapeParams.h"
#include "gfx/ICanvas.h"

#include <map>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

namespace shapes
{
	class Picture {
public:
    void AddShape(const ShapeParams& params) {
        if (m_shapes.contains(params.id)) {
            throw std::runtime_error("Shape with this ID already exists");
        }
    	auto geo = CreateShape(params);
    	m_shapes[params.id] = std::make_unique<shapes::IFigure>(
			params.id, params.color, std::move(geo));
        m_order.push_back(params.id);
    }

    void MoveShape(const std::string& id, double dx, double dy) {
        auto it = m_shapes.find(id);
        if (it == m_shapes.end()) throw std::runtime_error("Shape not found");
        it->second->Move(dx, dy);
    }

    void MovePicture(double dx, double dy) {
        for (auto& [id, shape] : m_shapes) {
            shape->Move(dx, dy);
        }
    }

    void DeleteShape(const std::string& id) {
        if (!m_shapes.contains(id)) throw std::runtime_error("Shape not found");
        m_shapes.erase(id);
        m_order.erase(std::remove(m_order.begin(), m_order.end(), id), m_order.end());
    }

    void EditShapeColor(const std::string& id, const std::string& color) {
        auto it = m_shapes.find(id);
        if (it == m_shapes.end()) throw std::runtime_error("Shape not found");
        it->second->SetColor(color);
    }

	void ChangeShape(const std::string& id, const ShapeParams& params) {
    	auto it = m_shapes.find(id);
    	if (it == m_shapes.end()) throw std::runtime_error("Shape not found");

    	ShapeParams p = params;
    	p.id = id;
    	p.color = it->second->GetColor();

    	auto geo = CreateShape(p);
    	it->second->SetGeometry(std::move(geo));
    }

    std::vector<std::string> ListAllShapes() const {
        std::vector<std::string> result;
        int index = 1;
        for (const auto& id : m_order) {
            auto it = m_shapes.find(id);
            if (it != m_shapes.end()) {
                result.push_back(std::to_string(index++) + " " + it->second->GetInfo());
            }
        }
        return result;
    }

		void DrawShape(const std::string& id, gfx::ICanvas& canvas) const {
    	auto it = m_shapes.find(id);
    	if (it == m_shapes.end()) throw std::runtime_error("Shape not found");
    	it->second->Draw(canvas);
    }

		void DrawPicture(gfx::ICanvas& canvas) const {
    	for (const auto& id : m_order) {
    		auto it = m_shapes.find(id);
    		if (it != m_shapes.end()) it->second->Draw(canvas);
    	}
    }
private:
    std::unique_ptr<IShapeGeometry> CreateShape(const ShapeParams& params) {
        switch (params.type) {
            case ShapeType::CIRCLE: {
                if (params.params.size() < 1) throw std::runtime_error("Circle needs radius");
            	double r = std::stod(params.params[0]);
            	if (r < 0) throw std::runtime_error("Radius must be non-negative");
                return std::make_unique<shapes::Circle>(params.x, params.y, r);
            }
            case ShapeType::RECTANGLE: {
                if (params.params.size() < 2) throw std::runtime_error("Rectangle needs width and height");
            	double w = std::stod(params.params[0]);
            	double h = std::stod(params.params[1]);
            	if ((w < 0) || (h < 0)) throw std::runtime_error("Width and height must be non-negative");
                return std::make_unique<shapes::Rectangle>(params.x, params.y, w, h);
            }
            case ShapeType::TRIANGLE: {
                if (params.params.size() < 4) throw std::runtime_error("Triangle needs 3 points");
                return std::make_unique<shapes::Triangle>(params.x, params.y,
                                                  std::stod(params.params[0]), std::stod(params.params[1]),
                                                  std::stod(params.params[2]), std::stod(params.params[3]));
            }
            case ShapeType::LINE: {
                if (params.params.size() < 2) throw std::runtime_error("Line needs end point");
                return std::make_unique<shapes::Line>(params.x, params.y,
                                              std::stod(params.params[0]), std::stod(params.params[1]));
            }
            case ShapeType::TEXT: {
                if (params.params.size() < 2) throw std::runtime_error("Text needs size and content");
            	double size = std::stod(params.params[0]);
            	if (size < 0) throw std::runtime_error("Font size must be non-negative");
                return std::make_unique<shapes::Text>(params.x, params.y,
                                              size, params.params[1]);
            }
            default:
                throw std::runtime_error("Unknown shape type");
        }
    }

    std::map<std::string, std::unique_ptr<IFigure>> m_shapes;
    std::vector<std::string> m_order;
};
}