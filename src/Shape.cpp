// Shape.cpp
#include "../header/Shape.h"

// Initialisation du membre statique
int Shape::nextId = 1;

Shape::Shape() : id(nextId++) {
    // L'ID est automatiquement incrémenté
}