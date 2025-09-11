#include "Game.h"
#include <memory>

namespace game_2d {

    void Game::run() {

        spawnPlayer();

        while (window.isOpen())
        {

            if(!m_paused) {
                m_frame_ctr++;
                entityManager.update();
                sEnemySpawner();
                sMovement();
                sCollision();
            }

            sUserInput();
            sRender();
        }
    }

    void Game::sRender() {

        window.clear(sf::Color::Black);

        for(auto &e : entityManager.getEntities()) {
            e->cTransform->angle += 1.0f;
            e->cShape->sfShape.setRotation(e->cTransform->angle);
            window.draw(e->cShape->sfShape);
        }
 
        window.display();
    }

    void Game::sCollision() {

        borderCollision("enemy");
        
        for(auto &e : entityManager.getEntities("enemy")) {
            for(auto &b : entityManager.getEntities("bullet")) {
                auto v1 = b->cTransform->pos;
                auto v2 = e->cTransform->pos;
                if(v1.dist(v2) <= b->cCollision->radius + e->cCollision->radius) {
                    e->kill();
                }
            }
        }
    }

    void Game::sUserInput() {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

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
                    case sf::Keyboard::W:
                    player->cInput->shoot = true;
                    return;
                    case sf::Keyboard::P:
                    m_paused = !m_paused;
                    break;
                    default:
                    return;
                }
                player->cInput->press = true;

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
                    default:
                    return;
                }
                player->cInput->press = false;
            }
        }
    }

    void Game::sMovement() {
        Vec2 dir = { 0, 0 };

        if(player->cInput->up) {
            dir.y -= 1;
        } else if(player->cInput->down) {
            dir.y += 1;
        }

        if(player->cInput->right) {
            dir.x += 1;
        } else if(player->cInput->left) {
            dir.x += -1;
        }
        if(player->cInput->press)
            player->cTransform->direction = dir;

        player->cTransform->velocity = dir * 3;

        if(player->cInput->shoot) {
            spawnBullet();
            player->cInput->shoot = false;
        }

        /* update position */
        for(auto &e : entityManager.getEntities()) {
            e->cTransform->pos += e->cTransform->velocity;
            e->cShape->updatePos(e->cTransform->pos.x, e->cTransform->pos.y);
        }
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
            auto e = entityManager.addEntity("bullet", 8, sf::Color::Green, 9);
            e->cTransform->velocity = player->cTransform->direction * 2;
            e->cTransform->pos = player->cTransform->pos;
    }

    void Game::spawnEnemy() {
            auto e = entityManager.addEntity("enemy", 16, sf::Color::Red, 3);
            e->cTransform->velocity = { 2, 2 };
            e->cTransform->pos = { 80, 80 };
    }

    void Game::spawnPlayer() {
        auto entity = entityManager.addEntity("player", 10, sf::Color::Blue, 4);
        player = entity;
    }

    void Game::sEnemySpawner() {
        if(m_frame_ctr % 120 == 0)
            spawnEnemy();
    }

}