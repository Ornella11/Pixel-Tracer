// Line.cpp
#include "../header/Line.h"
#include "../header/Point.h"
#include "../header/Pixel.h"
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
        int x1 = p1.getPosX();
        int y1 = p1.getPosY();
        int x2 = p2.getPosX();
        int y2 = p2.getPosY();

        int dx = std::abs(x2- x1);
        int dy = std::abs(y2- y1);
        int sx = (x1 < x2) ? 1 :-1;
        int sy = (y1 < y2) ? 1 :-1;
        int delta = dx- dy;

        while (x1 != x2 || y1 != y2) {
            pixels.push_back(Pixel(x1, y1));
            int e = 2 * delta;
            if (e >-dy) {
                delta-= dy;
                x1 += sx;
            }
            if (e < dx) {
                delta += dx;
                y1 += sy;
            }
        }
        pixels.push_back(Pixel(x2, y2));
        return pixels;
        }
  