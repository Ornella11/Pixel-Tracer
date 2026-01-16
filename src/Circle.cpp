// Circle.cpp
#include "../header/Circle.h"
#include "../header/Pixel.h"
#include "../header/Point.h"

Circle::Circle(const Point& c, int r)
    : Shape(), center(c), radius(r) {}

Circle::Circle(int x, int y, int r)
    : Shape(), center(x, y), radius(r) {}

void Circle::print() const {
    std::cout << "CIRCLE " << center.getPosX() << " "
        << center.getPosY() << " " << radius << std::endl;
}

std::vector<Pixel> Circle::toPixels() const {
    std::vector<Pixel> pixels;

    int x = 0;
    int y = radius;
    int d = radius- 1;
    int cx = center.getPosX();
    int cy = center.getPosY();

    while (y >= x) {
        // 8 octants
        pixels.push_back(Pixel(cx + x, cy + y));
        pixels.push_back(Pixel(cx + y, cy + x));
        pixels.push_back(Pixel(cx- x, cy + y));
        pixels.push_back(Pixel(cx- y, cy + x));
        pixels.push_back(Pixel(cx + x, cy- y));
        pixels.push_back(Pixel(cx + y, cy- x));
        pixels.push_back(Pixel(cx- x, cy- y));
        pixels.push_back(Pixel(cx- y, cy- x));

        if (d >= 2 * x) {
            d-= 2 * x + 1;
            x++;
        } 
        else if (d < 2 * (radius- y)) {
            d += 2 * y- 1;
            y--;
        } 
        else {
            d += 2 * (y- x- 1);
            y--;
            x++;
        }
    }
    return pixels;
}