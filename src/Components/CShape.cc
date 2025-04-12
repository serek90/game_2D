#include "CShape.h"
#include <iostream>


namespace game_2d {
    void CShape::setColor(Color color)
    {
        switch(color) {
            case Color::Red:
                sfShape->setFillColor(sf::Color(250, 30, 30));
                break;
            case Color::Green:
                sfShape->setFillColor(sf::Color(25, 250, 30));
                break;
        }
    }

    void CShape::updatePos(float w, float h)
    {
        sfShape->setPosition(w,h);
    }

    CShape::CShape(float xS,  Color color) : xSize{xS * 2}
    {

        sfShape = std::make_shared<sf::CircleShape>(xS);

        sfShape->setPosition(100.0f,100.0f);
        setColor(color);
        speed.x = speed.y = 1.0f;
    }

}