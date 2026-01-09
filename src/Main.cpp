#include "Area.h"
#include "Line.h"
#include "Circle.h"

int main() {
    Area drawZone(12, 14);
    auto shape1 = std::make_shared<Line>(5, 5, 10, 10);
    auto shape2 = std::make_shared<Circle>(5, 5, 4);
    drawZone.addShape(shape1);
    drawZone.addShape(shape2);
    drawZone.draw();
    drawZone.print();
    drawZone.erase();
    drawZone.draw();
    drawZone.print();
}
