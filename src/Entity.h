#ifndef __ENTITY_H
#define __ENTITY_H
#include <iostream>
#include <memory>
#include "Components/CTransform.h"
#include "Components/CShape.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace game_2d {
    class Entity {
        const size_t m_id = 0;
        const std::string m_tag = "Default";
        bool m_alive = true;
    public:
        std::shared_ptr<CTransform> cTransform;
        std::shared_ptr<CShape> cShape;
        //std::shared_ptr<CBBox> cBBox;
        //std::shared_ptr<CName> cName;

        Entity(const std::string& tag, size_t id) {}
        Entity(const std::string& tag, size_t id, float xS, float yS, shape_type shape_t, Color color) {
            cShape = std::make_shared<CShape>(xS, yS, shape_t, color);
        }
        sf::Shape& getSfShape() { return cShape->getSfShape(); }
   };
}


#endif /* __ENTITY_H */