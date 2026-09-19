//
// Created by maxim on 12.09.2026.
//

#ifndef FIGURES_SHAPESCOMMANDHANDLER_H
#define FIGURES_SHAPESCOMMANDHANDLER_H
#include "Shapes/Picture.h"

#include <iostream>
#include <sstream>

namespace CommandHandler
{
class ShapesCommandHandler
{
	public:
	ShapesCommandHandler() = default;
	void Execute(std::istream& in = std::cin, std::ostream& out = std::cout)
	{
		std::string line;
		std::string command;
		while (true) {
			try
			{
				getline(in, line);
				std::istringstream iss(line);
				iss >> command;
				if (command == "AddShape")
				{
					std::cout << 1;
				}
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what();
			}
		}
	}
	private:
	Picture m_picture;
};
}

#endif //FIGURES_SHAPESCOMMANDHANDLER_H