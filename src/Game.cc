#include "Game.h"
#include <memory>

namespace game_2d {

    void Game::run() {

        for(int i = 0; i < 10; i++)
        {
            entityManager.addEntity("entity1");
        }
        for(int i = 10; i < 20; i++)
        {
            entityManager.addEntity("entity2");
        }

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            sRender();
            sCollision();
        }
    }

    void Game::sRender() {

        window.clear(sf::Color::Black);

        auto ent = entityManager.getEntities("entity2");
        for(auto &e : ent) {
            window.draw(e->getSfShape());
        }

        entityManager.update();

        window.display();
    }

    void Game::sCollision() {
        auto ent = entityManager.getEntities("entity2");
        for(auto &e : ent) {
            if(e->cTransform->pos.x <= 0 || e->cTransform->pos.x >= windowWidth)
            {
                std::cout << "Hit border X" << std::endl;
                e->cTransform->velocity.x *= -1;
            }
            if(e->cTransform->pos.y  <= 0 || e->cTransform->pos.y  >= windowHeight)
            {
                std::cout << "Hit border Y" << std::endl;
                e->cTransform->velocity.y *= -1;
            }
        }    
    }
}