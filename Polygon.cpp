// Polygon.cpp
#include "Polygon.h"
#include "Line.h"

Polygon::Polygon() : Shape() {}

Polygon::Polygon(const std::vector<Point>& pts)
    : Shape(), points(pts) {}

Polygon::Polygon(const std::vector<int>& coords) : Shape() {
    if (coords.size() % 2 != 0) {
        std::cerr << "Erreur: nombre impair de coordonnées" << std::endl;
        return;
    }

    for (size_t i = 0; i + 1 < coords.size(); i += 2) {
        points.push_back(Point(coords[i], coords[i+1]));
    }
}

void Polygon::addPoint(const Point& p) {
    points.push_back(p);
}

void Polygon::addPoint(int x, int y) {
    points.push_back(Point(x, y));
}

void Polygon::print() const {
    std::cout << "POLYGON";
    for (const auto& p : points) {
    std::cout << " " << p.getPosX() << " " << p.getPosY();
    }
    std::cout << std::endl;
}

std::vector<Pixel> Polygon::toPixels() const {
    std::vector<Pixel> pixels;

    if (points.size() < 2) return pixels;

    // Relier chaque paire de points consécutifs
    for (size_t i = 0; i < points.size()- 1; ++i) {
        Line line(points[i], points[i+1]);
        auto linePixels = line.toPixels();
        pixels.insert(pixels.end(), linePixels.begin(), linePixels.end());
    }

    return pixels;
}