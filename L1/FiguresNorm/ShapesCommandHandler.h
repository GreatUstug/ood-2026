#ifndef FIGURES_SHAPESCOMMANDHANDLER_H
#define FIGURES_SHAPESCOMMANDHANDLER_H
#pragma once
#include "Shapes/Picture.h"
#include <iostream>
#include <sstream>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

namespace CommandHandler {

class ShapesCommandHandler {
public:
    ShapesCommandHandler(shapes::Picture& picture,
                         gfx::ICanvas& canvas,
                         std::function<bool()> pump)
        : m_picture(picture), m_canvas(canvas), m_pump(std::move(pump)) {}

    void Execute(std::istream& in = std::cin, std::ostream& out = std::cout) {
        std::string line;
        out << "=== Shapes Console ===\n";

        while (m_pump() && std::getline(in, line)) {
            if (line.empty()) continue;
            std::istringstream iss(line);
            std::string cmd;
            iss >> cmd;

            try {
                if (cmd == "AddShape")         HandleAddShape(iss, out);
                else if (cmd == "MoveShape")   HandleMoveShape(iss, out);
                else if (cmd == "MovePicture") HandleMovePicture(iss, out);
                else if (cmd == "DeleteShape") HandleDeleteShape(iss, out);
                else if (cmd == "ChangeColor") HandleChangeColor(iss, out);
                else if (cmd == "ChangeShape") HandleChangeShape(iss, out);
                else if (cmd == "List")        HandleList(out);
                else if (cmd == "DrawShape")   HandleDrawShape(iss, out);
                else if (cmd == "DrawPicture") HandleDrawPicture(out);
                else if (cmd == "Exit")        break;
                else out << "Unknown command: " << cmd << "\n";
            } catch (const std::exception& e) {
                out << "Error: " << e.what() << "\n";
            }
        }
    }

private:
    void HandleDrawShape(std::istringstream& iss, std::ostream&) {
        std::string id;
        if (!(iss >> id)) throw std::runtime_error("Invalid DrawShape");
        m_picture.DrawShape(id, m_canvas);
        m_pump();
    }

    void HandleDrawPicture(std::ostream&) {
        m_picture.DrawPicture(m_canvas);
        m_pump();
    }

    void HandleAddShape(std::istringstream& iss, std::ostream& out) {
        ShapeParams p;
        std::string typeStr;
        if (!(iss >> p.id >> p.color >> typeStr))
            throw std::runtime_error("Invalid AddShape syntax");

        if (typeStr == "circle")         p.type = ShapeType::CIRCLE;
        else if (typeStr == "rectangle") p.type = ShapeType::RECTANGLE;
        else if (typeStr == "triangle")  p.type = ShapeType::TRIANGLE;
        else if (typeStr == "line")      p.type = ShapeType::LINE;
        else if (typeStr == "text")      p.type = ShapeType::TEXT;
        else throw std::runtime_error("Unknown type: " + typeStr);

        if (!(iss >> p.x >> p.y)) throw std::runtime_error("Missing coordinates");
        p.params = GetParams(p.type, iss);

        m_picture.AddShape(p);
        out << "Added: " << p.id << "\n";
    }

    void HandleMoveShape(std::istringstream& iss, std::ostream&) {
        std::string id; double dx, dy;
        if (!(iss >> id >> dx >> dy)) throw std::runtime_error("Invalid MoveShape");
        m_picture.MoveShape(id, dx, dy);
    }

    void HandleMovePicture(std::istringstream& iss, std::ostream&) {
        double dx, dy;
        if (!(iss >> dx >> dy)) throw std::runtime_error("Invalid MovePicture");
        m_picture.MovePicture(dx, dy);
    }

    void HandleDeleteShape(std::istringstream& iss, std::ostream&) {
        std::string id;
        if (!(iss >> id)) throw std::runtime_error("Invalid DeleteShape");
        m_picture.DeleteShape(id);
    }

    void HandleChangeColor(std::istringstream& iss, std::ostream&) {
        std::string id, color;
        if (!(iss >> id >> color)) throw std::runtime_error("Invalid ChangeColor");
        m_picture.EditShapeColor(id, color);
    }

    void HandleList(std::ostream& out) {
        for (const auto& s : m_picture.ListAllShapes()) out << s << "\n";
    }

    void HandleChangeShape(std::istringstream& iss, std::ostream& out) {
        std::string id, typeStr;
        if (!(iss >> id >> typeStr))
            throw std::runtime_error("Invalid ChangeShape syntax");

        ShapeParams p;
        p.id = id;
        if (typeStr == "circle")         p.type = ShapeType::CIRCLE;
        else if (typeStr == "rectangle") p.type = ShapeType::RECTANGLE;
        else if (typeStr == "triangle")  p.type = ShapeType::TRIANGLE;
        else if (typeStr == "line")      p.type = ShapeType::LINE;
        else if (typeStr == "text")      p.type = ShapeType::TEXT;
        else throw std::runtime_error("Unknown type: " + typeStr);

        if (!(iss >> p.x >> p.y)) throw std::runtime_error("Missing coordinates");
        p.params = GetParams(p.type, iss);

        m_picture.ChangeShape(id, p);
        out << "Changed: " << id << "\n";
    }

    std::vector<std::string> GetParams(const ShapeType& type, std::istringstream& iss) {
        std::vector<std::string> params;
        if (type == ShapeType::TEXT) {
            std::string sizeStr, textLine;
            iss >> sizeStr;
            std::getline(iss, textLine);
            if (!textLine.empty() && textLine[0] == ' ') textLine.erase(0, 1);
            params.push_back(sizeStr);
            params.push_back(textLine);
        } else {
            std::string param;
            while (iss >> param) params.push_back(param);
        }
        return params;
    }

    shapes::Picture&       m_picture;
    gfx::ICanvas&          m_canvas;
    std::function<bool()>  m_pump;
};

}
#endif //FIGURES_SHAPESCOMMANDHANDLER_H