#ifndef __CCOLLISION_H
#define __CCOLLISION_H

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

    class CCollision {
        float radius;
        CCollision(float r) : radius{r} {}
    };

}


#endif /* __CCOLLISION_H */