//
// Created by maxim on 11.09.2026.
//

// main.cpp
#include "SFML/Graphics.hpp"
#include "gfx/SFMLCanvas.h"
#include "Shapes/Picture.h"
#include "ShapeParams.h"
#include <iostream>

int main() {
	// 1. Создаем окно
	sf::RenderWindow window(sf::VideoMode(800, 600), "Figures Test");

	// 2. Загружаем шрифт (положите arial.ttf рядом с exe)
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cerr << "Error: arial.ttf not found!\n";
		return -1;
	}

	// 3. Создаем канвас для этого окна
	SFMLCanvas canvas(window, font);

	// 4. Добавляем тестовую фигуру
	Picture picture;
	ShapeParams p;
	p.type = ShapeType::CIRCLE;
	p.id = "c1";
	p.color = "#ff0000";
	p.x = 400;
	p.y = 300;
	p.params = {"100"}; // радиус

	try {
		picture.AddShape(p);
	} catch (const std::exception& e) {
		std::cerr << "AddShape error: " << e.what() << "\n";
	}

	// 5. Главный цикл отрисовки
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Рисуем всё в тот же канвас (накопительно)
		picture.DrawAll(canvas);
		window.display();
	}

	return 0;
}