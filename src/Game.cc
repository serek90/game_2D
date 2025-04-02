#include "Game.h"
#include <memory>

namespace game_2d {

    void Game::run() {
        /* CShape should not be there */
        std::shared_ptr<Entity> shape = std::make_shared<Entity>("tt",0,40.0f, 40.0f, shape_type::Circle, Color::Red);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
    
            window.clear(sf::Color::Black);
            window.draw(shape->getSfShape()); // Drawing our shape.
            window.display();
        }
    }
}