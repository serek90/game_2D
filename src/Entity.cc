#include "Entity.h"



namespace game_2d {

    Entity::Entity(const std::string& tag, size_t id, float xS,  sf::Color color, int p) : m_tag{tag} {
        cShape = std::make_shared<CShape>(xS, p, color);

        Vec2 pos(20,20);

        Vec2 vel(0,0);
        cTransform = std::make_shared<CTransform>(pos, vel, 3.4);
        cCollision = std::make_shared<CCollision>(xS);
        cInput = std::make_shared<CInput>();
    }
}

