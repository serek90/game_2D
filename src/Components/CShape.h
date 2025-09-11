#ifndef __CSHAPE_H
#define __CSHAPE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

namespace game_2d {

    class CShape
    {
        float xSize;
        int _points;

    public:
        sf::CircleShape sfShape;
        CShape(float xS, int points, sf::Color color);

        void updatePos(float w, float h);
    };
}


#endif /* __CSHAPE_H */