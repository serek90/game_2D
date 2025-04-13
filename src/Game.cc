#include "Game.h"
#include <memory>

namespace game_2d {

    void Game::run() {
        player = entityManager.addEntity("player", 10, Color::Green);
        player->cInput = std::make_unique<CInput>();
        /*
        for(int i = 0; i < 10; i++)
        {
            entityManager.addEntity("entity1", 2 * i, Color::Green);
        }
        for(int i = 10; i < 20; i++)
        {
            if(i%2)
               entityManager.addEntity("entity2", 2 * i, Color::Green);
            else
               entityManager.addEntity("entity2", 2 * i, Color::Red);
        } */

        /* ToDo: Implement PAUSE system */
        while (window.isOpen())
        {
            entityManager.update();

            sEnemySpawner();
            sMovement();
            sCollision();
            sUserInput();
            sRender();
        }
    }

    void Game::sRender() {

        window.clear(sf::Color::Black);

        auto ent = entityManager.getEntities("entity2");
        for(auto &e : ent) {
            window.draw(e->getSfShape());
        }
        window.draw(player->getSfShape());

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

    void Game::sUserInput() {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {

                switch(event.key.code) {
                    case sf::Keyboard::Up:
                    std::cout<< "Key Up pressed" << std::endl;
                    player->cInput->up = true;
                    break;
                    case sf::Keyboard::Down:
                    std::cout<< "Key Down pressed" << std::endl;
                    player->cInput->down = true;
                    break;
                    case sf::Keyboard::Left:
                    std::cout<< "Key Left pressed" << std::endl;
                    player->cInput->left = true;
                    break;
                    case sf::Keyboard::Right:
                    std::cout<< "Key Right pressed" << std::endl;
                    player->cInput->right = true;
                    break;
                }

            } else if (event.type == sf::Event::KeyReleased) {

                switch(event.key.code) {
                    case sf::Keyboard::Up:
                    std::cout<< "Key Up released" << std::endl;
                    player->cInput->up = false;
                    break;
                    case sf::Keyboard::Down:
                    std::cout<< "Key Down released" << std::endl;
                    player->cInput->down = false;
                    break;
                    case sf::Keyboard::Left:
                    std::cout<< "Key Left released" << std::endl;
                    player->cInput->left = false;
                    break;
                    case sf::Keyboard::Right:
                    std::cout<< "Key Right released" << std::endl;
                    player->cInput->right = false;
                    break;              
                }
            }
        }
    }

    void Game::sMovement() {
        if(player->cInput->up) {
            player->cTransform->velocity.y = -3;
        } else if(player->cInput->down) {
            player->cTransform->velocity.y = 3;
        } else {
            player->cTransform->velocity.y = 0;            
        }

        if(player->cInput->right) {
            player->cTransform->velocity.x = 3;
        } else if(player->cInput->left) {
            player->cTransform->velocity.x = -3;
        } else {
            player->cTransform->velocity.x = 0;            
        }

        player->update();
    }

}