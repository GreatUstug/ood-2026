#include "SFML/Graphics.hpp"
#include "gfx/SFMLCanvas.h"
#include "Shapes/Picture.h"
#include "ShapeParams.h"
#include <iostream>

int main() {
	// 1. Окно — VideoMode теперь требует Vector2u
	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Figures Test");

	// 2. Шрифт — loadFromFile переименован в openFromFile
	sf::Font font;
	if (!font.openFromFile("arial.ttf")) {
		std::cerr << "Error: arial.ttf not found!\n";
		return -1;
	}

	// 3. Канвас
	SFMLCanvas canvas(window, font);

	// 4. Фигура
	Picture picture;
	ShapeParams p;
	p.type = ShapeType::CIRCLE;
	p.id = "c1";
	p.color = "#ff0000";
	p.x = 400;
	p.y = 300;
	p.params = {"100"};

	try {
		picture.AddShape(p);
	} catch (const std::exception& e) {
		std::cerr << "AddShape error: " << e.what() << "\n";
	}

	// 5. Главный цикл
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();          // не забываем очищать окно!
		picture.DrawAll(canvas);
		window.display();
	}

	return 0;
}