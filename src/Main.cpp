#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>
#include <memory>
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
    int currentLayerId = -1;

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
        } else if (cmd == "select" && ss.str().find("layer ") != std::string::npos) {
            std::string dummy;
            int id;
            ss >> dummy >> id; // On consomme "layer" pour lire l'ID
            bool found = false;
            for (const auto& l : layers) {
                if (l.getId() == id) {
                    found = true;
                    break;
                }
            }
            if (found) {
                currentLayerId = id;
                std::cout << "Couche " << id << " sélectionnée\n";
            } else {
                std::cout << "Couche " << id << " introuvable\n";
            }
        } else if (cmd == "delete" && ss.str().find("layer ") != std::string::npos) {
            std::string dummy;
            int id;
            ss >> dummy >> id; // On consomme "layer" pour lire l'ID
            layers.erase(std::remove_if(layers.begin(), layers.end(),
                [id](const Layer& l) { return l.getId() == id; }), layers.end());
            if (currentLayerId == id) currentLayerId = -1;
            std::cout << "Couche " << id << " supprimée\n";
        } else if (cmd == "set" && ss.str().find("layer visible ") != std::string::npos) {
            std::string d1, d2;
            int id;
            ss >> d1 >> d2 >> id; // On consomme "layer" et "visible"
            bool found = false;
            for (auto& l : layers) {
                if (l.getId() == id) {
                    l.setVisible(true);
                    found = true;
                    std::cout << "Couche " << id << " visible\n";
                    break;
                }
            }
            if (!found) {
                std::cout << "Couche " << id << " introuvable\n";
            }
        } else if (cmd == "set" && ss.str().find("layer invisible ") != std::string::npos) {
            std::string d1, d2;
            int id;
            ss >> d1 >> d2 >> id; // On consomme "layer" et "invisible"
            bool found = false;
            for (auto& l : layers) {
                if (l.getId() == id) {
                    l.setVisible(false);
                    found = true;
                    std::cout << "Couche " << id << " invisible\n";
                    break;
                }
            }
            if (!found) {
                std::cout << "Couche " << id << " introuvable\n";
            }
        } else if (cmd == "point") {
            int x, y;
            if (ss >> x >> y) {
                auto shape = std::make_shared<Point>(x, y);
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.addShape(shape);
                            shape->print();
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Arguments invalides pour point\n";
            }
        } else if (cmd == "line") {
            int x1, y1, x2, y2;
            if (ss >> x1 >> y1 >> x2 >> y2) {
                auto shape = std::make_shared<Line>(x1, y1, x2, y2);
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.addShape(shape);
                            shape->print();
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Arguments invalides pour line\n";
            }
        } else if (cmd == "circle") {
            int x, y, r;
            if (ss >> x >> y >> r) {
                auto shape = std::make_shared<Circle>(x, y, r);
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.addShape(shape);
                            shape->print();
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Arguments invalides pour circle\n";
            }
        } else if (cmd == "square") {
            int x, y, len;
            if (ss >> x >> y >> len) {
                auto shape = std::make_shared<Square>(x, y, len);
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.addShape(shape);
                            shape->print();
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Arguments invalides pour square\n";
            }
        } else if (cmd == "rectangle") {
            int x, y, w, h;
            if (ss >> x >> y >> w >> h) {
                auto shape = std::make_shared<Rectangle>(x, y, w, h);
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.addShape(shape);
                            shape->print();
                            break;
                        }
                    }
                }
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
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.addShape(shape);
                            shape->print();
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Le polygone nécessite au moins 3 points\n";
            }
        } else if (cmd == "plot") {
            drawZone.erase();
            for (const auto& l : layers) {
                if (l.isVisible()) {
                    for (const auto& s : l.getShapes()) {
                        drawZone.addShape(s);
                    }
                }
            }
            drawZone.draw();
            drawZone.print();
        } else if (cmd == "list") {
            if (currentLayerId == -1) {
                std::cout << "Aucune couche sélectionnée\n";
            } else {
                for (const auto& l : layers) {
                    if (l.getId() == currentLayerId) {
                        std::cout << "\nListe des formes de la couche " << currentLayerId << " :\n";
                        for (const auto& s : l.getShapes()) {
                            s->print();
                        }
                        break;
                    }
                }
            }
        } else if (cmd == "delete") {
            int id;
            if (ss >> id) {
                if (currentLayerId == -1) {
                    std::cout << "Aucune couche sélectionnée\n";
                } else {
                    for (auto& l : layers) {
                        if (l.getId() == currentLayerId) {
                            l.removeShape(id);
                            std::cout << "Forme supprimée de la couche " << currentLayerId << "\n";
                            break;
                        }
                    }
                }
            } else {
                std::cout << "ID invalide pour delete\n";
            }
        } else if (cmd == "erase") {
            if (currentLayerId == -1) {
                std::cout << "Aucune couche sélectionnée\n";
            } else {
                for (auto& l : layers) {
                    if (l.getId() == currentLayerId) {
                        l.clear();
                        std::cout << "Toutes les formes de la couche " << currentLayerId << " effacées\n";
                        break;
                    }
                }
            }
        } else if (cmd == "clear") {
            drawZone.clear();
            std::cout << "Écran effacé\n";
        } else if (cmd == "help") {
            std::cout << R"(
                Commandes :
                - list layers : afficher la liste des couches
                - new layer [nom] : créer une nouvelle couche
                - select layer [id] : sélectionner une couche pour ajouter des formes
                - delete layer [id] : supprimer une couche
                - set layer visible [id] : rendre une couche visible
                - set layer invisible [id] : rendre une couche invisible
                - point x y : ajouter un point
                - line x1 y1 x2 y2 : ajouter un segment reliant deux points (x1, y1) et (x2, y2)
                - circle x y radius : ajouter un cercle de centre (x, y) et de rayon radius
                - square x y length : ajouter un carré dont le coin supérieur gauche est (x, y) et de côté length.
                - rectangle x y width height : ajouter un rectangle dont le coin supérieur gauche est (x, y), de largeur width et de longueur height
                - polygon x1 y1 x2 y2 x3 y3 ... ... : ajouter un polygone avec la liste des points donnés
                - plot : rafraîchir l’écran pour afficher toutes les formes géométriques des couches visibles
                - list : afficher la liste des formes de la couche sélectionnée
                - delete [id] : supprimer une forme de la couche sélectionnée
                - erase : supprimer toutes les formes de la couche sélectionnée
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