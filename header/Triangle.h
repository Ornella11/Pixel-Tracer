#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include <vector>

class Triangle : public Shape {
private:
    Point p1, p2, p3;

public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    Triangle(const Point& pt1, const Point& pt2, const Point& pt3);
    ~Triangle() override = default;

    void print() const override;
    std::vector<Pixel> toPixels() const override;
};

#endif // TRIANGLE_H