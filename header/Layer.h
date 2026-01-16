// Point.h
#ifndef LAYER_H
#define LAYER_H

#include "../header/Shape.h"
#include "../header/Point.h"
#include <vector>
#include <iostream>
#include <memory>


class Layer {
    private:
    std::string name;
    int id;
    static int nextId;
    std::vector<std::shared_ptr<Shape>> shapes;
    bool visible;

    public:
        // Constructeur
        Layer();

        Layer(const std::string &layerName);

        // Destructeur
        ~Layer() = default;

        // Getters
        int getId() const { return id; }
        const std::string& getName() const { return name; }
        bool isVisible() const { return visible; }
        const std::vector<std::shared_ptr<Shape>>& getShapes() const {
            return shapes;
        }
        // Setters
        void setName(const std::string& n) { name = n; }
        void setVisible(bool v) { visible = v; }
        // Méthodes
        void addShape(std::shared_ptr<Shape> shape);
        void removeShape(int shapeId);
        void clear();
        void print() const;
};

# endif // LAYER_H
