// Circle.cpp
#include "Circle.h"
#include "Pixel.h"

Circle::Circle(const Point& c, int r)
    : Shape(), center(c), radius(r) {}

Circle::Circle(int x, int y, int r)
    : Shape(), center(x, y), radius(r) {}

void Circle::print() const {
    std::cout << "CIRCLE " << center.getPosX() << " "
        << center.getPosY() << " " << radius << std::endl;
}

std::vector<Pixel> Circle::toPixels() const {
    // Implémentation de l'algorithme d'Andres/Bresenham
    // (sera détaillée dans la partie 2)
    std::vector<Pixel> pixels;
    // ... code de l'algorithme ...
    return pixels;
}