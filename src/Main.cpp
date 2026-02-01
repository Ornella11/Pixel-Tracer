#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../header/Area.h"
#include "../header/Line.h"
#include "../header/Circle.h"
#include "../header/Point.h"
#include "../header/Layer.h"
#include "../header/Square.h"
#include "../header/Rectangle.h"
#include "../header/Polygon.h"


void afficherMenu() {
    std::cout << "\nVeuillez choisir une action :\n";
    std::cout << "A- Ajouter une forme\n";
    std::cout << "B- Afficher la liste des formes\n";
    std::cout << "C- Supprimer une forme\n";
    std::cout << "D- Tracer le dessin\n";
    std::cout << "E- Aide\n";
    std::cout << "F- Quitter\n";
    std::cout << ">> Votre choix : ";
}

int main() {
    std::string choix;
    std::string num;
    bool continuer = true;
    Area drawZone(20, 20);
    std::vector<Layer> layers;
    std::list<std::shared_ptr<Shape>> shapes;

    while (continuer) {
        afficherMenu();
        if (!std::getline(std::cin, choix)) break;

        if (choix == "A" || choix == "a") {
            std::cout << "\n--- Sous-menu : Ajouter une forme ---\n"
                    << "1- Ajouter un point\n"
                    << "2- Ajouter une ligne\n"
                    << "3- Ajouter un cercle\n"
                    << "4- Ajouter un carre\n"
                    << "5- Ajouter un rectangle\n"
                    << "6- Ajouter un polygone\n"
                    << "7- Revenir au menu precedent\n"
                    << ">> Votre choix : ";

            std::getline(std::cin, num);

            if (num == "1") {
                int x1, y1;
                std::cout << "Saisir x1 y1: ";
                if (std::cin >> x1 >> y1) {
                    auto shape = std::make_shared<Point>(x1, y1);
                    shapes.push_back(shape);     
                    shape->print();
                } else {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                }
            }
            else if (num == "2") {
                int x1, y1, x2, y2;
                std::cout << "Saisir le premier point x1 y1: ";
                if (!(std::cin >> x1 >> y1)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }
                std::cout << "Saisir le deuxieme point x2 y2: ";
                if (!(std::cin >> x2 >> y2)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }

                auto shape = std::make_shared<Line>(x1, y1, x2, y2);
                shapes.push_back(shape);         
                shape->print();

            }
            else if (num == "3") {
                int x1, y1, r;
                std::cout << "Saisir lepoint centre x1 y1: ";
                if (!(std::cin >> x1 >> y1)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }
                std::cout << "Saisir le rayon du cercle: ";
                if (!(std::cin >> r)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }

                auto shape = std::make_shared<Circle>(x1, y1, r);
                shapes.push_back(shape);         
                shape->print();

            }
             else if (num == "4") {
                int x1, y1, len;
                std::cout << "Saisir x1 y1: ";
                if (!(std::cin >> x1 >> y1)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }
                std::cout << "Saisir la longueur: ";
                if (!(std::cin >> len)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }

                auto shape = std::make_shared<Square>(x1, y1, len);
                shapes.push_back(shape);         
                shape->print();

            }
            else if (num == "5") {
                int x1, y1, len, w;
                std::cout << "Saisir x1 y1: ";
                if (!(std::cin >> x1 >> y1)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }
                std::cout << "Saisir la longueur: ";
                if (!(std::cin >> len)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }
                 std::cout << "Saisir la largeur: ";
                if (!(std::cin >> w)) {
                    std::cout << "Entree invalide\n";
                    std::cin.clear();
                    continue;
                }

                auto shape = std::make_shared<Rectangle>(x1, y1, len, w);
                shapes.push_back(shape);         
                shape->print();
            }
             else if (num == "6") {
                int n;
                std::cout << "Nombre de points (>=3): ";
                std::cin >> n;

                std::vector<Point> pts;

                for (int i = 0; i < n; ++i) {
                    int x, y;
                    std::cout << "Point " << i+1 << " (x y): ";
                    std::cin >> x >> y;
                    pts.emplace_back(x, y);
                }
                auto shape = std::make_shared<Polygon>(pts);
                shapes.push_back(shape);
                shape->print();
            }
        }
        else if (choix == "B" || choix == "b" || choix == "list") {
            std::cout << "\nListe des formes :\n";
            for (const auto& s : shapes) {
                if (s) s->print();
            }
        }
        else if (choix == "C" || choix == "c" || choix == "delete") {
            int id;
            std::cout << "Saisir l'ID de la forme à supprimer : ";
            if (!(std::cin >> id)) {
                std::cout << "ID invalide\n";
                std::cin.clear();
            }
            shapes.remove_if([id](const std::shared_ptr<Shape>& s) {
            return s->getId() == id;
            std::cout << "Suppression réussi !";
            });
        }

        else if (choix == "D" || choix == "d" || choix == "plot") {
            std::cout << "Affichage du dessin en cours...\n";

        }
        else if (choix == "E" || choix == "e" || choix == "help") {
            std::cout << R"(
        - point x y : ajouter un point
        - line x1 y1 x2 y2 : ajouter un segment reliant deux points (x1, y1) et (x2, y2)
        - circle x y radius : ajouter un cercle de centre (x, y) et de rayon radius
        - square x y length : ajouter un carré dont le coin supérieur gauche est (x, y) et de côté length
        - rectangle x y width height : ajouter un rectangle dont le coin supérieur gauche est (x, y), de largeur width et de hauteur height
        - polygon x1 y1 x2 y2 x3 y3 ... : ajouter un polygone avec la liste des points donnés
        - plot : rafraîchir l’écran pour afficher toutes les formes
        - list : afficher la liste des formes
        - delete id : supprimer une forme par son identifiant
        - erase : supprimer toutes les formes
        - help : afficher cette aide
        )";
        }
        else if (choix == "F" || choix == "f" || choix == "exit") {
            continuer = false;
            std::cout << "Fermeture du programme. Au revoir !\n";
        }
        else if (!choix.empty()) {
            std::cout << "Erreur : '" << choix << "' est une commande ou une option invalide !\n";
        }
    }

    return 0;
}