#include "../header/Area.h"
#include "../header/Line.h"
#include "../header/Circle.h"



void displayMenu() {
    std::cout << "\n--- Main Menu ---" << std::endl;
    std::cout << "1. Ajouter une forme" << std::endl;
    std::cout << "2. Afficher la liste des formes" << std::endl;
    std::cout << "3. Supprimer une forme" << std::endl;
    std::cout << "4. Tracer le dessin" << std::endl;
    std::cout << "5. Aide" << std::endl;
}
 
int main() {
    char choix;
    bool running = true;
 
    while (running) {
        displayMenu();
        std::cin >> choix;
        choix = toupper(choix);
 
        switch (choix) {
            case '1':
                std::cout << "Ajouter..." << std::endl;
                break;
            case '2':
                std::cout << "Afficher..." << std::endl;
                break;
            case '3':
                std::cout << "Supprimer..." << std::endl;
                break;
            case '4':
                std::cout << "Tracer..." << std::endl;
                break;
            case '5':
                running = false;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
        }
    }
    return 0;
 
}
