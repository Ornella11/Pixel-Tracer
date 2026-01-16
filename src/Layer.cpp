// Layer.cpp
# include "../header/Layer.h"
# include <iostream>
# include <algorithm>

int Layer::nextId = 1;
Layer::Layer() : id(nextId++), name("Layer_" + std::to_string(id)),
visible(true) {}
Layer::Layer(const std::string& layerName) : 
id(nextId++), name(layerName), visible(true) {}

void Layer::addShape(std::shared_ptr<Shape> shape) {
shapes.push_back(shape);
}
void Layer::removeShape(int shapeId) {
shapes.erase(
std::remove_if(shapes.begin(), shapes.end(),
[shapeId](const std::shared_ptr<Shape>& s) {
return s->getId() == shapeId;
}),
shapes.end()
);
}
void Layer::clear() {
shapes.clear();
}
void Layer::print() const {
std::cout << "Layer " << id << " (" << name << ") - "
<< (visible ? "Visible" : "Hidden") << " - "
<< shapes.size() << " forme(s)" << std::endl;
}