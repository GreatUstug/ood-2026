//
// Created by maxim on 14.09.2026.
//

#ifndef FIGURES_ICANVAS_H
#define FIGURES_ICANVAS_H

// gfx/ICanvas.h
#pragma once
#include <string>
#include <algorithm>
#include <stdexcept>

namespace gfx {
    struct Color {
        unsigned char r, g, b, a;

        Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255)
            : r(r), g(g), b(b), a(a) {}

        static Color Parse(const std::string& str) {
            if (!str.empty() && (str[0] == '#' || str.length() == 6)) {
                size_t start = (str[0] == '#') ? 1 : 0;
                if (str.length() - start != 6)
                    throw std::runtime_error("Invalid hex color: " + str);

                unsigned long val = std::stoul(str.substr(start), nullptr, 16);
                return Color(
                    static_cast<unsigned char>((val >> 16) & 0xFF),
                    static_cast<unsigned char>((val >> 8) & 0xFF),
                    static_cast<unsigned char>(val & 0xFF)
                );
            }

            if (str == "red") return {255, 0, 0};
            if (str == "green") return {0, 255, 0};
            if (str == "blue") return {0, 0, 255};
            if (str == "black") return {0, 0, 0};
            if (str == "white") return {255, 255, 255};

            throw std::runtime_error("Unknown color format: " + str);
        }
    };

    class ICanvas {
    public:
        virtual ~ICanvas() = default;
        virtual void SetColor(const Color& c) = 0;
        virtual void MoveTo(double x, double y) = 0;
        virtual void LineTo(double x, double y) = 0;
        virtual void DrawEllipse(double cx, double cy, double rx, double ry) = 0;
        virtual void DrawText(double left, double top, double fontSize, const std::string& text) = 0;
    };
}
#endif //FIGURES_ICANVAS_H