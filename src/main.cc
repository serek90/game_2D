#include <iostream>
#include "Game.h"

int main()
{
    game_2d::Game game("game_config.txt");
    game.run();

    return 0;
}