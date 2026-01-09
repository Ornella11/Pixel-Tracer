// Pixel.cpp
# include "Pixel.h"

Pixel::Pixel() : x(0), y(0) {}

Pixel::Pixel(int px, int py) : x(px), y(py) {}

Pixel::Pixel(const Pixel& other) : x(other.x), y(other.y) {}

Pixel::~Pixel() {}

Pixel& Pixel::operator=(const Pixel& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Pixel::operator==(const Pixel& other) const {
    return (x == other.x && y == other.y);
}