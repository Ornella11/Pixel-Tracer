// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
    private:
        Point topLeft;
        int width;
        int height;

    public:
        // Constructeurs
        Rectangle(const Point& tl, int w, int h);
        Rectangle(int x, int y, int w, int h);

        // Destructeur
        ~Rectangle() override = default;

        // Getters
        const Point& getTopLeft() const { return topLeft; }
        int getWidth() const { return width; }
        int getHeight() const { return height; }

        // Setters
        void setTopLeft(const Point& tl) { topLeft = tl; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        
        // Méthodes override
        void print() const override;
        std::vector<Pixel> toPixels() const override;
};
#endif // RECTANGLE_H