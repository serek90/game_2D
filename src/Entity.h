#ifndef __ENTITY_H
#define __ENTITY_H
#include <iostream>
#include <memory>
#include "Components/CTransform.h"
#include "Components/CShape.h"
#include "Components/CCollision.h"
#include "Components/CScore.h"
#include "Components/CInput.h"
#include "Components/CLifeSpan.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Components/Vec2.h"

namespace game_2d {
    class Entity {
        const size_t m_id = 0;
        const std::string m_tag = "Default";
        bool m_alive = true;
    public:
        std::shared_ptr<CTransform> cTransform;
        std::shared_ptr<CShape> cShape;
        std::shared_ptr<CCollision> cCollision;
        std::shared_ptr<CScore> cScore;
        std::shared_ptr<CInput> cInput;
        std::shared_ptr<CLifeSpan> cLifeSpan;
        Entity(const std::string& tag, size_t id) {}
        Entity(const std::string& tag, size_t id, float xS,  Color color) {
            cShape = std::make_shared<CShape>(xS, color);

            static int i = 0;
            Vec2 pos(20.0f * i,20.0f * i);
            i++;
            Vec2 vel(1,1);
            cTransform = std::make_shared<CTransform>(pos, vel, 3.4);
        }
        void update() {
            cTransform->pos += cTransform->velocity;
            cShape->updatePos(cTransform->pos.x, cTransform->pos.y);
        }
        sf::Shape& getSfShape() { 
            return cShape->getSfShape(); 
        }
   };
}


#endif /* __ENTITY_H */