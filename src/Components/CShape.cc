#include "CShape.h"
#include <iostream>


namespace game_2d {

    void CShape::updatePos(float w, float h)
    {
        sfShape->setPosition(w,h);
    }

    CShape::CShape(float xS,  sf::Color color) : xSize{xS * 2}
    {

        sfShape = std::make_shared<sf::CircleShape>(xS);

        sfShape->setPosition(100.0f,100.0f);
        sfShape->setFillColor(color);
        speed.x = speed.y = 1.0f;
    }

}