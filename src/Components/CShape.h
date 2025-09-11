#ifndef __CSHAPE_H
#define __CSHAPE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

namespace game_2d {

    struct CShape
    {
        sf::CircleShape sfShape;

        CShape(float radius,  int points, sf::Color color) : sfShape(radius, points)
        {
            sfShape.setPosition(100.0f,100.0f);
            sfShape.setOrigin(radius, radius);
            sfShape.setFillColor(color);
        }
    };
}


#endif /* __CSHAPE_H */