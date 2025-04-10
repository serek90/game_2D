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

enum class Color { Red, Green, Blue };
enum class shape_type { Rectangle, Circle, Polygon};

namespace game_2d {

    class CShape
    {
        std::shared_ptr<sf::Shape> sfShape;
        shapesSpeed speed;
        float xSize;
        float ySize;

        void setXSpeed(float Xspeed) { speed.x = Xspeed; }
        void setYSpeed(float Yspeed) { speed.y = Yspeed; }

        void setColor(Color color);

    public:

        CShape(float xS, float yS, Color color);

        void checkBorder(float w, float h);

        void updatePos(float w, float h);
        sf::Shape& getSfShape() { return *sfShape; }
    };
}


#endif /* __CSHAPE_H */