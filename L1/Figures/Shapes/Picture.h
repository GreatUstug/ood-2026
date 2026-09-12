//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_PICTURE_H
#define FIGURES_PICTURE_H
#include <unordered_map>
#include "Shape.h"

#include <string>

class Picture
{
	public:
	Picture(){};
	private:
		std::unordered_map<std::string, Shape> m_shapes;
};

#endif //FIGURES_PICTURE_H