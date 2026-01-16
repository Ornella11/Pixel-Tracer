// Square.cpp
#include "../header/Square.h"
#include "../header/Line.h"
#include <cmath>

std::vector<Pixel> Square::toPixels() const {
    std::vector<Pixel> pixels;
    int x = topLeft.getPosX();
    int y = topLeft.getPosY();

    // 4 côtés du carré
    Line top(x, y, x, y + length);
    Line right(x, y + length, x + length, y + length);
    Line bottom(x + length, y + length, x + length, y);
    Line left(x + length, y, x, y);

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