// Square.cpp
#include "../header/Rectangle.h"
#include "../header/Line.h"
#include <cmath>


Rectangle::Rectangle(int x, int y, int w, int len)
    : Shape(), topLeft(x, y), width(w), height(len) {}

Rectangle::Rectangle(const Point& tl, int w, int len)
    : Shape(), topLeft(tl), width(w), height(len) {}

void Rectangle::print() const {
    std::cout << "Rectangle " << topLeft.getPosX() << " " << topLeft.getPosY() << " " << width << " " << height << std::endl;;
}

std::vector<Pixel> Rectangle::toPixels() const {
    std::vector<Pixel> pixels;
    int x = topLeft.getPosX();
    int y = topLeft.getPosY();

    // 4 côtés du rectangle
    Line top(x, y, x, y + width);
    Line right(x, y + width, x + height, y + width);
    Line bottom(x + height, y + width, x + height, y);
    Line left(x + height, y, x, y);
    auto pixelsTop = top.toPixels();
    auto pixelsRight = right.toPixels();
    auto pixelsBottom = bottom.toPixels();

    auto pixelsLeft = left.toPixels();
    pixels.insert(pixels.end(), pixelsTop.begin(), pixelsTop.end());
    pixels.insert(pixels.end(), pixelsRight.begin(), pixelsRight.end());
    pixels.insert(pixels.end(), pixelsBottom.begin(), pixelsBottom.end());
    pixels.insert(pixels.end(), pixelsLeft.begin(), pixelsLeft.end());
    return pixels;
}