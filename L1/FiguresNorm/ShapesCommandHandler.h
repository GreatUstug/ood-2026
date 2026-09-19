// ShapesCommandHandler.h
#pragma once
#include "Shapes/Picture.h"
#include <iostream>
#include <sstream>

namespace CommandHandler {

class ShapesCommandHandler {
public:
    explicit ShapesCommandHandler(Picture& picture) : m_picture(picture) {}

    void Execute(std::istream& in = std::cin, std::ostream& out = std::cout) {
        std::string line;
        out << "=== Shapes Console ===\n";
        out << "Commands: AddShape, MoveShape, List, DrawPicture, Exit\n";

        while (std::getline(in, line)) {
            if (line.empty()) continue;
            std::istringstream iss(line);
            std::string cmd;
            iss >> cmd;

            try {
                if (cmd == "AddShape") HandleAddShape(iss, out);
                else if (cmd == "MoveShape") HandleMoveShape(iss, out);
                else if (cmd == "MovePicture") HandleMovePicture(iss, out);
                else if (cmd == "DeleteShape") HandleDeleteShape(iss, out);
                else if (cmd == "ChangeColor") HandleChangeColor(iss, out);
                else if (cmd == "List") HandleList(out);
                else if (cmd == "DrawPicture") m_picture.RenderToWindow(); // Ждет закрытия окна
                else if (cmd == "Exit") break;
                else out << "Unknown command: " << cmd << "\n";
            } catch (const std::exception& e) {
                out << "Error: " << e.what() << "\n";
            }
        }
    }

private:
    Picture& m_picture;

    void HandleAddShape(std::istringstream& iss, std::ostream& out) {
        ShapeParams p;
        std::string typeStr;
        if (!(iss >> p.id >> p.color >> typeStr)) throw std::runtime_error("Invalid AddShape syntax");

        if (typeStr == "circle") p.type = ShapeType::CIRCLE;
        else if (typeStr == "rectangle") p.type = ShapeType::RECTANGLE;
        else if (typeStr == "triangle") p.type = ShapeType::TRIANGLE;
        else if (typeStr == "line") p.type = ShapeType::LINE;
        else if (typeStr == "text") p.type = ShapeType::TEXT;
        else throw std::runtime_error("Unknown type: " + typeStr);

        if (!(iss >> p.x >> p.y)) throw std::runtime_error("Missing coordinates");
        std::string param;
        while (iss >> param) p.params.push_back(param);

        m_picture.AddShape(p);
        out << "Added: " << p.id << "\n";
    }

    void HandleMoveShape(std::istringstream& iss, std::ostream& out) {
        std::string id; double dx, dy;
        if (!(iss >> id >> dx >> dy)) throw std::runtime_error("Invalid MoveShape");
        m_picture.MoveShape(id, dx, dy);
    }

    void HandleMovePicture(std::istringstream& iss, std::ostream& out) {
        double dx, dy;
        if (!(iss >> dx >> dy)) throw std::runtime_error("Invalid MovePicture");
        m_picture.MovePicture(dx, dy);
    }

    void HandleDeleteShape(std::istringstream& iss, std::ostream& out) {
        std::string id;
        if (!(iss >> id)) throw std::runtime_error("Invalid DeleteShape");
        m_picture.DeleteShape(id);
    }

    void HandleChangeColor(std::istringstream& iss, std::ostream& out) {
        std::string id, color;
        if (!(iss >> id >> color)) throw std::runtime_error("Invalid ChangeColor");
        m_picture.EditShapeColor(id, color);
    }

    void HandleList(std::ostream& out) {
        for (const auto& s : m_picture.ListAllShapes()) out << s << "\n";
    }
};

} // namespace CommandHandler