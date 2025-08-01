#include "Entity.h"



namespace game_2d {

    Entity::Entity(const std::string& tag, size_t id, float xS,  sf::Color color, int p) : m_tag{tag} {
        cShape = std::make_shared<CShape>(xS, p, color);

        static int i = 0;
        std::srand(std::time({})); // use current time as seed for random generator
        int rW = xS * 10;//std::rand() % 640;
        int rH = xS * 10; //std::rand() %480;
        Vec2 pos(rW,rH);
        i++;
        //Vec2 vel(xS,xS);
        Vec2 vel(0,0);
        cTransform = std::make_shared<CTransform>(pos, vel, 3.4);
        cCollision = std::make_shared<CCollision>(xS);
        cInput = std::make_shared<CInput>();
    }
}

