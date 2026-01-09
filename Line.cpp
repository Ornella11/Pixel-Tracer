// Line.cpp
#include "Line.h"
#include "Pixel.h"
#include <cmath>

Line::Line(const Point& point1, const Point& point2)
    : Shape(), p1(point1), p2(point2) {}

Line::Line(int x1, int y1, int x2, int y2)
    : Shape(), p1(x1, y1), p2(x2, y2) {}

void Line::print() const {
    std::cout << "LINE " << p1.getPosX() << " " << p1.getPosY()
              << " " << p2.getPosX() << " " << p2.getPosY()
              << std::endl;
}

std::vector<Pixel> Line::toPixels() const {
    // Implémentation de l'algorithme de Bresenham
    // (sera détaillée dans la partie 2)
    std::vector<Pixel> pixels;
    // ... code de l'algorithme ...
    return pixels;
}