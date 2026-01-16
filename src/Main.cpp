#include "../header/Area.h"
#include "../header/Line.h"
#include "../header/Circle.h"

 
int main() {
    std::string choix;
    std::cout << ">>";
    std::getline(std::cin, choix);

    if (choix == "help")
    {
       std::cout << R"(Commandes disponibles :
        - clear : effacer l’écran
        - exit : quitter le programme
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
    } else {
        std::cout << "Erreur : commande invalide !" << std::endl;
    }
    
}
