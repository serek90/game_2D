#include "CShape.h"
#include <iostream>


namespace game_2d {

    void CShape::updatePos(float w, float h)
    {
        sfShape.setPosition(w,h);
    }

    CShape::CShape(float xS,  int points, sf::Color color) : xSize{xS * 2}, _points{points}, sfShape(xS, points)
    {
        sfShape.setPosition(100.0f,100.0f);
        sfShape.setOrigin(sfShape.getRadius(), sfShape.getRadius());
        sfShape.setFillColor(color);
    }

}