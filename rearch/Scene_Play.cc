#include "Scene_Play.h"

namespace game_2d {

Scene_Play::Scene_Play(GameEngine *game) {
    m_game = game;
    spawnPlayer();
}

void Scene_Play::sRender() {

    m_game->window().clear(sf::Color::Black);

    //m_text.setString("points: " + std::to_string(m_score));
    //m_window.draw(m_text);

    for(auto &e : m_entities.getEntities()) {
        e->cTransform->angle += 1.0f;
        e->cShape->sfShape.setRotation(e->cTransform->angle);
        m_game->window().draw(e->cShape->sfShape);
    }
 
    m_game->window().display();
}

void Scene_Play::sDoAction(Action action) {

}

void Scene_Play::sEnemySpawner() {
    if(m_currentFrame % m_enemySpawnTime == 0)
        spawnEnemy();
}

void Scene_Play::spawnEnemy() {
    auto e = m_entities.addEntity("enemy", 16, sf::Color::Red, 3);

    e->cTransform->velocity = { 2, 2 };

    float ex = std::rand() % m_game->window().getSize().x;
    float ey = std::rand() % m_game->window().getSize().y;

    e->cTransform->pos = { ex, ey };
}

void Scene_Play::sMovement() {
    Vec2 dir = { 0, 0 };

    /* update position */
    float deltaTime = m_clock.restart().asSeconds();
    for(auto &e : m_entities.getEntities()) {
        e->cTransform->pos += e->cTransform->velocity * deltaTime * 20;
        e->cShape->sfShape.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
    }
}

void Scene_Play::update() {
    sEnemySpawner();
    sMovement();
    sCollision();
    m_currentFrame++;
    m_entities.update();
}

void Scene_Play::borderCollision(std::string str) {
    for(auto &e : m_entities.getEntities(str)) {
        if(e->cTransform->pos.x <= 0 || e->cTransform->pos.x >= m_game->window().getSize().x) {
            e->cTransform->velocity.x *= -1;
        }
        if(e->cTransform->pos.y  <= 0 || e->cTransform->pos.y  >= m_game->window().getSize().y) {
            e->cTransform->velocity.y *= -1;
        }
    }
}

void Scene_Play::sCollision() {

    borderCollision("enemy");

    for(auto &e : m_entities.getEntities("enemy")) {
        for(auto &b : m_entities.getEntities("bullet")) {
            auto v1 = b->cTransform->pos;
            auto v2 = e->cTransform->pos;
            if(v1.dist(v2) <= b->cCollision->radius + e->cCollision->radius) {
                e->kill();
            }
        }

        /* player collision */
        auto v1 = m_player->cTransform->pos;
        auto v2 = e->cTransform->pos;
        if(v1.dist(v2) <= m_player->cCollision->radius + e->cCollision->radius) {
            e->kill();
        }
    }

    for(auto &b : m_entities.getEntities("bullet")) {
        if(b->cLifeSpan->remaining-- == 0)
            b->kill();
    }
}

void Scene_Play::spawnBullet() {
    auto e = m_entities.addEntity("bullet", 8, sf::Color::Green, 9);
    e->cTransform->velocity = m_player->cTransform->direction * 8;
    e->cTransform->pos = m_player->cTransform->pos;
    e->cLifeSpan = std::make_shared<CLifeSpan>(40);
}

void Scene_Play::spawnPlayer() {
    auto entity = m_entities.addEntity("player", 20, sf::Color::Blue, 8);
    m_player = entity;
}

} /* namespace game_2d */