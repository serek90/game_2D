#include "Game.h"
#include <memory>
#include <fstream>

namespace game_2d {

Game::Game(const std:: string &path)
    : m_window(sf::VideoMode(windowWidth, windowHeight), "SFML_works") {

    // TODO:: read config file here and write to config structures
    std::fstream fin(path);
    m_window.setFramerateLimit(60);
}

void Game::run() {

    spawnPlayer();
    spawnText();

    while (m_window.isOpen()) {

        if(!m_paused) {
            m_frame_ctr++;
            m_entities.update();
            sEnemySpawner();
            sMovement();
            sCollision();
        }
        sUserInput();
        sRender();
    }
}

void Game::sRender() {

    m_window.clear(sf::Color::Black);

    m_text.setString("points: " + std::to_string(m_score));
    m_window.draw(m_text);

    for(auto &e : m_entities.getEntities()) {
        e->cTransform->angle += 1.0f;
        e->cShape->sfShape.setRotation(e->cTransform->angle);
        m_window.draw(e->cShape->sfShape);
    }
 
    m_window.display();
}

void Game::sCollision() {

    borderCollision("enemy");
        
    for(auto &e : m_entities.getEntities("enemy")) {
        for(auto &b : m_entities.getEntities("bullet")) {
            auto v1 = b->cTransform->pos;
            auto v2 = e->cTransform->pos;
            if(v1.dist(v2) <= b->cCollision->radius + e->cCollision->radius) {
                e->kill();
                m_score++;
            }
        }
    }

    for(auto &b : m_entities.getEntities("bullet")) {
        if(b->cLifeSpan->remaining-- == 0)
            b->kill();
    }
}

void Game::sUserInput() {
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            m_window.close();
            return;
        }

        if (event.type == sf::Event::KeyPressed) {

            switch(event.key.code) {
                case sf::Keyboard::Up:
                m_player->cInput->up = true;
                break;
                case sf::Keyboard::Down:
                m_player->cInput->down = true;
                break;
                case sf::Keyboard::Left:
                m_player->cInput->left = true;
                break;
                case sf::Keyboard::Right:
                m_player->cInput->right = true;
                break;
                case sf::Keyboard::W:
                m_player->cInput->shoot = true;
                return;
                case sf::Keyboard::P:
                m_paused = !m_paused;
                break;
                default:
                return;
            }
            m_player->cInput->press = true;

        } else if (event.type == sf::Event::KeyReleased) {

            switch(event.key.code) {
                case sf::Keyboard::Up:
                m_player->cInput->up = false;
                break;
                case sf::Keyboard::Down:
                m_player->cInput->down = false;
                break;
                case sf::Keyboard::Left:
                m_player->cInput->left = false;
                break;
                case sf::Keyboard::Right:
                m_player->cInput->right = false;
                break;
                default:
                return;
            }
            m_player->cInput->press = false;
        }
    }
}

void Game::sMovement() {
    Vec2 dir = { 0, 0 };

    if(m_player->cInput->up) {
        dir.y -= 1;
    } else if(m_player->cInput->down) {
        dir.y += 1;
    }

    if(m_player->cInput->right) {
        dir.x += 1;
    } else if(m_player->cInput->left) {
        dir.x += -1;
    }
    if(m_player->cInput->press)
        m_player->cTransform->direction = dir;

    m_player->cTransform->velocity = dir * 3;

    if(m_player->cInput->shoot) {
        spawnBullet();
        m_player->cInput->shoot = false;
    }

    /* update position */
    for(auto &e : m_entities.getEntities()) {
        e->cTransform->pos += e->cTransform->velocity;
        e->cShape->sfShape.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
    }
}

void Game::borderCollision(std::string str) {
    for(auto &e : m_entities.getEntities(str)) {
        if(e->cTransform->pos.x <= 0 || e->cTransform->pos.x >= windowWidth) {
            e->cTransform->velocity.x *= -1;
        }
        if(e->cTransform->pos.y  <= 0 || e->cTransform->pos.y  >= windowHeight) {
            e->cTransform->velocity.y *= -1;
        }
    }
}

void Game::spawnBullet() {
    auto e = m_entities.addEntity("bullet", 8, sf::Color::Green, 9);
    e->cTransform->velocity = m_player->cTransform->direction * 8;
    e->cTransform->pos = m_player->cTransform->pos;
    e->cLifeSpan = std::make_shared<CLifeSpan>(40);
}

void Game::spawnEnemy() {
     auto e = m_entities.addEntity("enemy", 16, sf::Color::Red, 3);

     e->cTransform->velocity = { 2, 2 };

    float ex = std::rand() % m_window.getSize().x;
    float ey = std::rand() % m_window.getSize().y;
    e->cTransform->pos = { ex, ey };
}

void Game::spawnPlayer() {
    auto entity = m_entities.addEntity("player", 20, sf::Color::Blue, 8);
    m_player = entity;
}

void Game::spawnText() {
    if (!m_font.loadFromFile("arial.ttf"))
        std::cout << "Font loading error\n";
}

void Game::sEnemySpawner() {
    if(m_frame_ctr % m_enemySpawnTime == 0)
        spawnEnemy();
}

}