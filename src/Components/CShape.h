#ifndef __CSHAPE_H
#define __CSHAPE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

struct shapesSpeed
{
    float x;
    float y;
};


enum class shape_type { Rectangle, Circle, Polygon};

namespace game_2d {

    class CShape
    {

        shapesSpeed speed;
        float xSize;
        int _points;

    public:
        std::shared_ptr<sf::CircleShape> sfShape;
        CShape(float xS, int points, sf::Color color);

        void updatePos(float w, float h);
        sf::Shape& getSfShape() { return *sfShape; }
    };
}


#endif /* __CSHAPE_H */