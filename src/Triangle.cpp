#include "../header/Triangle.h"
#include "../header/Line.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : p1(x1, y1), p2(x2, y2), p3(x3, y3) {}

Triangle::Triangle(const Point& pt1, const Point& pt2, const Point& pt3)
    : p1(pt1), p2(pt2), p3(pt3) {}

void Triangle::print() const {
    std::cout << "Triangle: (" << p1.getPosX() << "," << p1.getPosY() << ") ("
              << p2.getPosX() << "," << p2.getPosY() << ") ("
              << p3.getPosX() << "," << p3.getPosY() << ")" << std::endl;
}

std::vector<Pixel> Triangle::toPixels() const {
    std::vector<Pixel> pixels;
    Line l1(p1, p2);
    Line l2(p2, p3);
    Line l3(p3, p1);
    auto pix1 = l1.toPixels();
    auto pix2 = l2.toPixels();
    auto pix3 = l3.toPixels();
    pixels.insert(pixels.end(), pix1.begin(), pix1.end());
    pixels.insert(pixels.end(), pix2.begin(), pix2.end());
    pixels.insert(pixels.end(), pix3.begin(), pix3.end());
    return pixels;
}