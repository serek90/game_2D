#include <iostream>
#include "GameEngine.h"

int main()
{
    game_2d::GameEngine game("game_config.txt");
    game.run();

    return 0;
}