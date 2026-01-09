// Shape.h
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <vector>
#include "../Point/Point.h"
// Déclaration anticipée
class Pixel;
class Shape {
    protected:
        int id;
        static int nextId;

    public:
        // Constructeur
        Shape();

        // Destructeur virtuel
        virtual ~Shape() = default;
        // Méthodes virtuelles pures (classe abstraite)
        virtual void print() const = 0;
        virtual std::vector<Pixel> toPixels() const = 0;
        // Getter
        int getId() const { return id; }
};

#endif // SHAPE_H