#ifndef FIGURES_SFMLCANVAS_H
#define FIGURES_SFMLCANVAS_H
#pragma once
#include "../gfx/ICanvas.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class SFMLCanvas : public gfx::ICanvas {
public:
    SFMLCanvas(sf::RenderWindow& window, sf::Font& font)
        : m_window(window), m_font(font), m_currentPos{0.f, 0.f}, m_currentColor(0, 0, 0, 255) {}

    void SetColor(const gfx::Color& c) override {
        m_currentColor = sf::Color(c.r, c.g, c.b, c.a);
    }

    void MoveTo(double x, double y) override {
        m_currentPos = {static_cast<float>(x), static_cast<float>(y)};
    }

    void LineTo(double x, double y) override {
        sf::Vertex line[] = {
            sf::Vertex(m_currentPos, m_currentColor),
            sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), m_currentColor)
        };
        m_window.draw(line, 2, sf::PrimitiveType::Lines);
        m_currentPos = {static_cast<float>(x), static_cast<float>(y)};
    }

    void DrawEllipse(double cx, double cy, double rx, double ry) override {
        float maxR = std::max(static_cast<float>(rx), static_cast<float>(ry));
        if (maxR <= 0) return;

        sf::CircleShape circle(maxR);
        circle.setPointCount(100);
        circle.setOrigin(sf::Vector2f(maxR, maxR));                    // <-- Vector2f
        circle.setPosition(sf::Vector2f(static_cast<float>(cx),
                                        static_cast<float>(cy)));      // <-- Vector2f
        circle.setScale(sf::Vector2f(static_cast<float>(rx / maxR),
                                     static_cast<float>(ry / maxR)));  // <-- Vector2f

        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineColor(m_currentColor);
        circle.setOutlineThickness(1.0f);

        m_window.draw(circle);
    }

    void DrawText(double left, double top, double fontSize, const std::string& text) override {
        sf::Text sfText(m_font);                                       // <-- конструктор требует шрифт
        sfText.setString(text);
        sfText.setCharacterSize(static_cast<unsigned>(fontSize));
        sfText.setFillColor(m_currentColor);
        sfText.setPosition(sf::Vector2f(static_cast<float>(left),
                                        static_cast<float>(top)));     // <-- Vector2f
        m_window.draw(sfText);
    }

private:
    sf::RenderWindow& m_window;
    sf::Font& m_font;
    sf::Vector2f m_currentPos;
    sf::Color m_currentColor;
};
#endif //FIGURES_SFMLCANVAS_H