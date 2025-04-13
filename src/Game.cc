#include "Game.h"
#include <memory>

namespace game_2d {

    void Game::run() {
        player = entityManager.addEntity("player", 10, sf::Color::Blue);
        player->cInput = std::make_unique<CInput>();

        for(int i = 0; i < 10; i++)
        {
            auto e = entityManager.addEntity("bullet", 2 * i, sf::Color::Green);
            e->cTransform->velocity.x = 1 * i/2;
            e->cTransform->velocity.y = 1 * i/2;            
        }
        for(int i = 10; i < 20; i++)
        {
            auto e  = entityManager.addEntity("enemy", 2 * i, sf::Color::Red);
            e->cTransform->velocity.x = 1 * i/2;
            e->cTransform->velocity.y = 1 * i/2;    
        }

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

        for(auto &e : entityManager.getEntities("enemy")) {
            window.draw(e->getSfShape());
        }
        for(auto &e : entityManager.getEntities("bullet")) {
            window.draw(e->getSfShape());
        }
        window.draw(player->getSfShape());

        window.display();
    }

    void Game::sCollision() {

        borderCollision("bullet");
        borderCollision("enemy");
        
        for(auto &e : entityManager.getEntities("enemy")) {
            for(auto &b : entityManager.getEntities("nullet")) {
                auto v1 = b->cTransform->pos;
                auto v2 = e->cTransform->pos;
                if(v1.dist(v2) <= b->cCollision->radius + e->cCollision->radius) {
                    std::cout << "Hey there is a hit" << std::endl;
                }
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
                    player->cInput->up = true;
                    break;
                    case sf::Keyboard::Down:
                    player->cInput->down = true;
                    break;
                    case sf::Keyboard::Left:
                    player->cInput->left = true;
                    break;
                    case sf::Keyboard::Right:
                    player->cInput->right = true;
                    break;
                }

            } else if (event.type == sf::Event::KeyReleased) {

                switch(event.key.code) {
                    case sf::Keyboard::Up:
                    player->cInput->up = false;
                    break;
                    case sf::Keyboard::Down:
                    player->cInput->down = false;
                    break;
                    case sf::Keyboard::Left:
                    player->cInput->left = false;
                    break;
                    case sf::Keyboard::Right:
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

        
        entityManager.update();
    }

    void Game::borderCollision(std::string str) {
        for(auto &e : entityManager.getEntities(str)) {
            if(e->cTransform->pos.x <= 0 || e->cTransform->pos.x >= windowWidth)
            {
                //std::cout << "Hit border X" << std::endl;
                e->cTransform->velocity.x *= -1;
            }
            if(e->cTransform->pos.y  <= 0 || e->cTransform->pos.y  >= windowHeight)
            {
                //std::cout << "Hit border Y" << std::endl;
                e->cTransform->velocity.y *= -1;
            }
        }
    }

    void Game::spawnBullet() {

    }

}