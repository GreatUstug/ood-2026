//
// Created by maxim on 14.09.2026.
//

#ifndef FIGURES_SFMLCANVAS_H
#define FIGURES_SFMLCANVAS_H
// SFMLCanvas.h
#pragma once
#include "../gfx/ICanvas.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class SFMLCanvas : public gfx::ICanvas {
public:
    SFMLCanvas(sf::RenderWindow& window, sf::Font& font)
        : m_window(window), m_font(font), m_currentPos{0, 0}, m_currentColor{0, 0, 0, 255} {}

    void SetColor(const gfx::Color& c) override {
        m_currentColor = sf::Color(c.r, c.g, c.b, c.a);
    }

    void MoveTo(double x, double y) override {
        m_currentPos = {static_cast<float>(x), static_cast<float>(y)};
    }

    void LineTo(double x, double y) override {
        sf::Vertex line[] = {
            sf::Vertex(m_currentPos, m_currentColor),
            sf::Vertex({static_cast<float>(x), static_cast<float>(y)}, m_currentColor)
        };
        m_window.draw(line, 2, sf::Lines);
        m_currentPos = {static_cast<float>(x), static_cast<float>(y)};
    }

    void DrawEllipse(double cx, double cy, double rx, double ry) override {
        // Эллипс в SFML делается через масштабирование круга
        float maxR = std::max(static_cast<float>(rx), static_cast<float>(ry));
        if (maxR <= 0) return;

        sf::CircleShape circle(maxR);
        circle.setPointCount(100); // Гладкость
        circle.setOrigin(maxR, maxR); // Центр в середине
        circle.setPosition(static_cast<float>(cx), static_cast<float>(cy));

        // Масштабируем до нужных радиусов
        circle.setScale(static_cast<float>(rx / maxR), static_cast<float>(ry / maxR));

        circle.setFillColor(sf::Color::Transparent); // Эллипс обычно контурный в вашем ТЗ?
        // Если нужен закрашенный: circle.setFillColor(m_currentColor);
        // Если нужен контур:
        circle.setOutlineColor(m_currentColor);
        circle.setOutlineThickness(1.0f);

        m_window.draw(circle);
    }

    void DrawText(double left, double top, double fontSize, const std::string& text) override {
        sf::Text sfText;
        sfText.setFont(m_font);
        sfText.setString(text);
        sfText.setCharacterSize(static_cast<unsigned>(fontSize));
        sfText.setFillColor(m_currentColor);
        sfText.setPosition(static_cast<float>(left), static_cast<float>(top));
        m_window.draw(sfText);
    }

private:
    sf::RenderWindow& m_window;
    sf::Font& m_font;
    sf::Vector2f m_currentPos;
    sf::Color m_currentColor;
};
#endif //FIGURES_SFMLCANVAS_H