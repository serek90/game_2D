#include <iostream>
//#include "Entity.h"
//#include "Vec2.h"
#include "Game.h"

//void doStuff(std::vector<Entity> &vec)
//{

//}

int main()
{
    //std::vector<Entity> vec_entity;
    //Vec2 p(200,3), v(4,5);
    //Entity e;
    //e.cTransform = std::make_shared<CTransform>(p,v);
    //vec_entity.push_back(e);

    //doStuff(vec_entity);

    game_2d::Game game;
    game.run();

    return 0;
}