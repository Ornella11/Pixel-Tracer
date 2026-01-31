#include <iostream>
#include <string>
#include <vector>
#include "../header/Area.h"
#include "../header/Line.h"
#include "../header/Circle.h"

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
    bool continuer = true;

    while (continuer) {
        afficherMenu();
        if (!std::getline(std::cin, choix)) break;

        if (choix == "A" || choix == "a") {
            std::cout << "\n--- Sous-menu : Ajouter une forme ---\n";
            std::cout << "1- Ajouter un point\n";
            std::cout << "2- Ajouter une ligne\n";
            std::cout << "3- Ajouter un cercle\n";
            std::cout << "4- Ajouter un carre\n";
            std::cout << "5- Ajouter un rectangle\n";
            std::cout << "6- Ajouter un polygone\n";
            std::cout << "7- Revenir au menu precedent\n";
            std::cout << ">> Votre choix : ";
        } 
        else if (choix == "B" || choix == "b" || choix == "list") {
            std::cout << "\nListe des formes géométriques :\n";
        }
        else if (choix == "C" || choix == "c" || choix == "delete") {
            std::cout << "Saisir l'ID de la forme à supprimer : ";
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