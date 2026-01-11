#include "../header/Area.h"
#include "../header/Line.h"

int main() {
    Area drawZone(12, 14);
    auto shape1 = std::make_shared<Line>(5, 5, 10, 10);
    drawZone.addShape(shape1);
    drawZone.draw();
    drawZone.print();
    drawZone.erase();
    drawZone.draw();
    drawZone.print();
}
