//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_SHAPE_H
#define FIGURES_SHAPE_H
#include <string>
#include <vector>

class Shape
{
	public:
		Shape(
			const std::string& name,
			const std::string& id,
			int x,
			int y,
			const std::vector<std::string>& params
			)
		{
			m_name = name;
			m_id = id;
			m_x = x;
			m_y = y;
			m_params = params;
		};
		virtual ~Shape() = default;
	private:
		std::string m_name;
		std::string m_id;
		int m_x;
		int m_y;
		std::vector<std::string> m_params;
};

#endif //FIGURES_SHAPE_H