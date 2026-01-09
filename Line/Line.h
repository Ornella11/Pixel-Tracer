// Line.h
#ifndef LINE_H
#define LINE_H
#include "../Shape/Shape.h"

class Line : 
    public Shape {
        private:
            Point p1;
            Point p2;

        public:
            // Constructeurs
            Line(const Point& point1, const Point& point2);
            Line(int x1, int y1, int x2, int y2);

            // Destructeur
            ~Line() override = default;

            // Getters
            const Point& getP1() const { return p1; }
            const Point& getP2() const { return p2; }

            // Setters
            void setP1(const Point& point) { p1 = point; }
            void setP2(const Point& point) { p2 = point; }

            // Méthodes override (implémentation des méthodes virtuelles pures)
            void print() const override;
            std::vector<Pixel> toPixels() const override;
    };

#endif // LINE_H