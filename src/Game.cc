#include "Game.h"

namespace game_2d {

    void Game::run() {
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
    
            window.clear(sf::Color::Black);
            window.display();
        }
    }
}