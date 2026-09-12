//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_SHAPESCOMMANDHANDLER_H
#define FIGURES_SHAPESCOMMANDHANDLER_H
#include "Shapes/Picture.h"

#include <iostream>

namespace CommandHandler
{
class ShapesCommandHandler
{
	public:
	ShapesCommandHandler() = default;
	void Execute(std::istream& in = std::cin, std::ostream& out = std::cout)
	{

	}
	private:
	Picture m_picture;
};
}

#endif //FIGURES_SHAPESCOMMANDHANDLER_H