# include "../header/Area.h"
#include "../header/Shape.h"
#include "../header/Pixel.h"   
#include <iostream>
# include <algorithm>

Area::Area(unsigned int w, unsigned int h)
    : width(w), height(h), mat(h, std::vector<bool>(w, false)) {}

void Area::addShape(std::shared_ptr<Shape> shape) {
    shapes.push_back(shape);
}

void Area::removeShape(int id) {
    shapes.erase(
        std::remove_if(shapes.begin(), shapes.end(),
            [id](const std::shared_ptr<Shape>& s) {
                return s->getId() == id;
            }),
        shapes.end()
    );
}

std::shared_ptr<Shape> Area::getShape(int id) const {
    auto it = std::find_if(shapes.begin(), shapes.end(),
        [id](const std::shared_ptr<Shape>& s) {
            return s->getId() == id;
        });

    return (it != shapes.end()) ? *it : nullptr;
}

void Area::clear() {
    for (auto& row : mat) {
        std::fill(row.begin(), row.end(), false);
    }
}

void Area::draw() {
    clear();
    
    for (const auto& shape : shapes) {
        auto pixels = shape->toPixels();
        for (const auto& pixel : pixels) {
            int x = pixel.getX();
            int y = pixel.getY();
            
            // Vérifier que le pixel est dans les limites
            if (x >= 0 && x < static_cast<int>(height) &&
                y >= 0 && y < static_cast<int>(width)) {
                mat[x][y] = true;
            }
        }
    }
}

void Area::print() const {
    for (const auto& row : mat) {
        for (bool pixel : row) {
            std::cout << (pixel ? '#' : '.');
        }
        std::cout << std::endl;
    }
}

void Area::erase() {
    shapes.clear();
    clear();
}