// Command.cpp
# include "../header/Command.h"
# include <sstream>
# include <iostream>
# include "../header/Line.h"
# include "../header/Circle.h"
# include "../header/Square.h"
# include "../header/Rectangle.h"
# include "../header/Polygon.h"

Command::Command() {}

void Command::addIntParam(int p) {
    intParams.push_back(p);
}

void Command::addStrParam(const std::string& p) {
    strParams.push_back(p);
}

void Command::parse(const std::string& line) {
    clear();
    std::istringstream iss(line);
    std::string token;

    // Premier token = nom de la commande
    if (!(iss >> name)) return;
    // Traiter les autres tokens
    while (iss >> token) {
        try {
            int num = std::stoi(token);
            addIntParam(num);
        } catch (const std::invalid_argument&) {
            addStrParam(token);
        } catch (const std::out_of_range&) {
            std::cerr << "Nombre hors limites: " << token << std::endl;
        }
    }
}

bool Command::execute(Area& area) {
    if (name == "point") {
        if (intParams.size() >= 2) {
            auto p = std::make_shared<Point>(intParams[0], intParams[1]);
            area.addShape(p);
            std::cout << "Point ajouté (ID: " << p->getId() << ")" << std::endl;
            return true;
        }
        std::cerr << "Usage: point x y" << std::endl;
    }
    else if (name == "line") {
        if (intParams.size() >= 4) {
            auto line = std::make_shared<Line>(
                intParams[0], intParams[1],
                intParams[2], intParams[3]
            );
            area.addShape(line);
            std::cout << "Ligne ajoutée (ID: " << line->getId() << ")" << std::endl;
            return true;
        }
        std::cerr << "Usage: line x1 y1 x2 y2" << std::endl;
    }
    else if (name == "circle") {
        if (intParams.size() >= 3) {
            auto circle = std::make_shared<Circle>(
                intParams[0], intParams[1], intParams[2]
            );
            area.addShape(circle);
            std::cout << "Cercle ajouté (ID: " << circle->getId() << ")" << std::endl;
            return true;
        }
        std::cerr << "Usage: circle x y radius" << std::endl;
    }

    else if (name == "square") {
        if (intParams.size() >= 3) {
            auto square = std::make_shared<Square>(
                intParams[0], intParams[1], intParams[2]
            );
            area.addShape(square);
            std::cout << "Carré ajouté (ID: " << square->getId() << ")" << std::endl;
            return true;
        }
        std::cerr << "Usage: square x y length" << std::endl;
    }

    else if (name == "rectangle") {
        if (intParams.size() >= 4) {
            auto rect = std::make_shared<Rectangle>(
                intParams[0], intParams[1],
                intParams[2], intParams[3]
            );
            area.addShape(rect);
        std::cout << "Rectangle ajouté (ID:)" << rect->getId() << ")" << std::endl;
        return true;
        }
        std::cerr << "Usage: rect x y length" << std::endl;
    }
}