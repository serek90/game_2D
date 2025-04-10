#include "CShape.h"


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

    void CShape::checkBorder(float w, float h)
    {
        if(w <= sfShape->getPosition().x + xSize || 0 >= sfShape->getPosition().x)
            speed.x *= -1.0f;
        if(h <= sfShape->getPosition().y + ySize || 0 >= sfShape->getPosition().y)
            speed.y *= -1.0f;
    }

    void CShape::updatePos(float w, float h)
    {
        sfShape->setPosition(sfShape->getPosition().x + speed.x, sfShape->getPosition().y + speed.y);
        checkBorder(w,h);
    }

    CShape::CShape(float xS, float yS, Color color) : xSize{xS * 2}, ySize{yS * 2} 
    {

        sfShape = std::make_shared<sf::CircleShape>(xS);

        sfShape->setPosition(100.0f,100.0f);
        setColor(color);
        speed.x = speed.y = 1.0f;
    }

}