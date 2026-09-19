//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_COORDS_H
#define FIGURES_COORDS_H
#include <string>
#include <vector>
enum class ShapeType {
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE,
	TEXT
};

enum class HandlerCommands {
	ADD_SHAPE,
};

struct ShapeParams
{
	ShapeType type;
	std::string id;
	std::string color;
	double x;
	double y;
	std::vector<std::string> params;
};

#endif //FIGURES_COORDS_H