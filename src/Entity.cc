#include "Entity.h"



namespace game_2d {
    void Entity::update() {
        cTransform->pos += cTransform->velocity;
        cShape->updatePos(cTransform->pos.x, cTransform->pos.y);
    }

    Entity::Entity(const std::string& tag, size_t id, float xS,  Color color) {
        cShape = std::make_shared<CShape>(xS, color);

        static int i = 0;
        std::srand(std::time({})); // use current time as seed for random generator
        int rW = std::rand() % 640;
        int rH = std::rand() %480;
        Vec2 pos(rW,rH);
        i++;
        //Vec2 vel(xS,xS);
        Vec2 vel(0,0);
        cTransform = std::make_shared<CTransform>(pos, vel, 3.4);
    }
}

