// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
private:
    Point center;
    int radius;

public:
    // Constructeurs
    Circle(const Point& c, int r);
    Circle(int x, int y, int r);

    // Destructeur
    ~Circle() override = default;

    // Getters
    const Point& getCenter() const { return center; }
    int getRadius() const { return radius; }

    // Setters
    void setCenter(const Point& c) { center = c; }
    void setRadius(int r) { radius = r; }
    
    // Méthodes override
    void print() const override;
    std::vector<Pixel> toPixels() const override;
};
#endif // CIRCLE_H