// Point.h
#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
    
    private:
        int posX;
        int posY;

    public:
        // Constructeurs
        Point();
        Point(int x, int y);
        Point(const Point &other);

        // Destructeur
        ~Point();

        // Getters
        int getPosX() const { return posX; }
        int getPosY() const { return posY; }

        // Setters
        void setPosX(int x) { posX = x; }
        void setPosY(int y) { posY = y; }

        // Méthodes
        void print() const;

        // Opérateurs
        Point &operator=(const Point &other);
        bool operator==(const Point &other) const;
    
    };

#endif // POINT_H