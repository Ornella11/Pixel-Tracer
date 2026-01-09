# ifndef AREA_H
# define AREA_H
# include <vector>
# include <memory>
# include "../Shape/Shape.h"

class Area {
    private:
        unsigned int width;
        unsigned int height;
        std::vector<std::vector<bool>> mat;
        std::vector<std::shared_ptr<Shape>> shapes;
        
    public:
        // Constructeur
        Area(unsigned int w, unsigned int h);

        // Destructeur
        ~Area() = default;

        // Getters
        unsigned int getWidth() const { return width; }
        unsigned int getHeight() const { return height; }
        const std::vector<std::shared_ptr<Shape>>& getShapes() const {
            return shapes;
        }

        // Méthodes de gestion des formes
        void addShape(std::shared_ptr<Shape> shape);
        void removeShape(int id);
        std::shared_ptr<Shape> getShape(int id) const;

        // Méthodes de dessin
        void clear();
        void draw();
        void print() const;
        void erase();
    
};

# endif // AREA_H