// Square.h
#ifndef SQUARE_H
#define SQUARE_H
#include "../header/Shape.h"
#include "../header/Point.h"

class Square : public Shape {
    private:
        Point topLeft;
        int length;

    public:
        // Constructeurs
        Square(const Point& tl, int len);
        Square(int x, int y, int len);

        // Destructeur
        ~Square() override = default;

        // Getters
        const Point& getTopLeft() const { return topLeft; }
        int getLength() const { return length; }

        // Setters
        void setTopLeft(const Point& tl) { topLeft = tl; }
        void setLength(int len) { length = len; }
        
        // Méthodes override
        void print() const override;
        std::vector<Pixel> toPixels() const override;
};
#endif // SQUARE_H