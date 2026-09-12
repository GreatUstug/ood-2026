//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_COORDS_H
#define FIGURES_COORDS_H
#include <string>
#include <vector>

using ShapeAddParams = std::vector<std::string>;

struct ShapeParams
{
	int num;
	std::string type;
	std::string id;
	std::string color;
	int x;
	int y;
	ShapeAddParams params;

};

#endif //FIGURES_COORDS_H