// Polygon.h
#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include <vector>

class Polygon : public Shape {
    private:
        std::vector<Point> points;
    public:
        // Constructeurs
        Polygon();
        Polygon(const std::vector<Point>& pts);
        Polygon(const std::vector<int>& coords); // coords: x1,y1,x2,y2,...
        
        // Destructeur
        ~Polygon() override = default;
        
        // Getters
        const std::vector<Point>& getPoints() const { return points; }
        int getNumPoints() const { return points.size(); }
        
        // Méthodes
        void addPoint(const Point& p);
        void addPoint(int x, int y);
        
        // Méthodes override
        void print() const override;
        std::vector<Pixel> toPixels() const override;
};
#endif // POLYGON_H