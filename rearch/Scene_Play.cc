#include "Scene_Play.h"

namespace game_2d {

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
    m_currentFrame++;
    m_entities.update();
}

} /* namespace game_2d */