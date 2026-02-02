#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include "../header/Area.h"
#include "../header/Line.h"
#include "../header/Circle.h"
#include "../header/Point.h"
#include "../header/Layer.h"
#include "../header/Square.h"
#include "../header/Rectangle.h"
#include "../header/Polygon.h"

int main() {
    std::string line;
    bool continuer = true;
    Area drawZone(100, 50);
    std::vector<Layer> layers;

    while (continuer) {
        std::cout << ">> ";
        if (!std::getline(std::cin, line)) break;

        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;

        if (cmd == "list" && ss.str().find("layers") != std::string::npos) {
            for (const auto& l : layers) l.print();
        } else if (cmd == "new" && ss.str().find("layer ") != std::string::npos) {
            std::string layerName = ss.str().substr(ss.str().find("layer ") + 6);
            if (layerName.empty()) {
                std::cout << "Erreur : nom de couche vide !\n";
                continue;
            }
            layers.emplace_back(layerName);
            for (const auto& l : layers) l.print();
        } else if (cmd == "point") {
            int x, y;
            if (ss >> x >> y) {
                auto shape = std::make_shared<Point>(x, y);
                drawZone.addShape(shape);
                shape->print();
            } else {
                std::cout << "Arguments invalides pour point\n";
            }
        } else if (cmd == "line") {
            int x1, y1, x2, y2;
            if (ss >> x1 >> y1 >> x2 >> y2) {
                auto shape = std::make_shared<Line>(x1, y1, x2, y2);
                drawZone.addShape(shape);
                shape->print();
            } else {
                std::cout << "Arguments invalides pour line\n";
            }
        } else if (cmd == "circle") {
            int x, y, r;
            if (ss >> x >> y >> r) {
                auto shape = std::make_shared<Circle>(x, y, r);
                drawZone.addShape(shape);
                shape->print();
            } else {
                std::cout << "Arguments invalides pour circle\n";
            }
        } else if (cmd == "square") {
            int x, y, len;
            if (ss >> x >> y >> len) {
                auto shape = std::make_shared<Square>(x, y, len);
                drawZone.addShape(shape);
                shape->print();
            } else {
                std::cout << "Arguments invalides pour square\n";
            }
        } else if (cmd == "rectangle") {
            int x, y, w, h;
            if (ss >> x >> y >> w >> h) {
                auto shape = std::make_shared<Rectangle>(x, y, w, h);
                drawZone.addShape(shape);
                shape->print();
            } else {
                std::cout << "Arguments invalides pour rectangle\n";
            }
        } else if (cmd == "polygon") {
            std::vector<Point> pts;
            int x, y;
            while (ss >> x >> y) {
                pts.emplace_back(x, y);
            }
            if (pts.size() >= 3) {
                auto shape = std::make_shared<Polygon>(pts);
                drawZone.addShape(shape);
                shape->print();
            } else {
                std::cout << "Le polygone nécessite au moins 3 points\n";
            }
        } else if (cmd == "plot") {
            drawZone.draw();
            drawZone.print();
        } else if (cmd == "list") {
            std::cout << "\nListe des formes :\n";
            for (const auto& s : drawZone.getShapes()) {
                s->print();
            }
        } else if (cmd == "delete") {
            int id;
            if (ss >> id) {
                drawZone.removeShape(id);
                std::cout << "Forme supprimée\n";
            } else {
                std::cout << "ID invalide pour delete\n";
            }
        } else if (cmd == "erase") {
            drawZone.erase();
            std::cout << "Toutes les formes effacées\n";
        } else if (cmd == "clear") {
            drawZone.clear();
            std::cout << "Écran effacé\n";
        } else if (cmd == "help") {
            std::cout << R"(
            Commandes :
            - list layers : afficher la liste des couches
            - new layer <nom> : créer une nouvelle couche
            - point x y : ajouter un point
            - line x1 y1 x2 y2 : ajouter un segment reliant deux points (x1, y1) et (x2, y2)
            - circle x y radius : ajouter un cercle de centre (x, y) et de rayon radius
            - square x y length : ajouter un carré dont le coin supérieur gauche est (x, y) et de côté length.
            - rectangle x y width height : ajouter un rectangle dont le coin supérieur gauche est (x, y), de largeur width et de longueur height
            - polygon x1 y1 x2 y2 x3 y3 ... ... : ajouter un polygone avec la liste des points donnés
            - plot : rafraîchir l’écran pour afficher toutes les formes géométriques de l’image
            - list : afficher la liste de l’ensemble des formes géométriques qui composent l’image
            - delete id : supprimer une forme à partir de son identifiant id.
            - erase : supprimer toutes les formes d’une image.
            - clear : effacer l’écran
            - help : afficher la liste des commandes ainsi qu’un mini mode d’emploi
            - exit : quitter le programme
            )";
        } else if (cmd == "exit") {
            continuer = false;
            std::cout << "Fermeture du programme. Au revoir !\n";
        } else if (!cmd.empty()) {
            std::cout << "Erreur : '" << cmd << "' est une commande invalide !\n";
        }
    }

    return 0;
}