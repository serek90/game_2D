#include "Scene_Play.h"

namespace game_2d {

void Scene_Play::sRender() {

    m_game->window().clear(sf::Color::Black);

    //m_text.setString("points: " + std::to_string(m_score));
    //m_window.draw(m_text);

    for(auto &e : m_entities.getEntities()) {
        std::cout << "Scene_Play::sRender(): entity_loop\n";
        e->cTransform->angle += 1.0f;
        e->cShape->sfShape.setRotation(e->cTransform->angle);
        m_game->window().draw(e->cShape->sfShape);
    }
 
    m_game->window().display();
}    

void Scene_Play::sEnemySpawner() {
    if(m_currentFrame % m_enemySpawnTime == 0)
        spawnEnemy();
}

void Scene_Play::spawnEnemy() {
    std::cout << "Scene_Play::spawnEnemy()\n";
    auto e = m_entities.addEntity("enemy", 16, sf::Color::Red, 3);

    e->cTransform->velocity = { 2, 2 };

    //float ex = std::rand() % m_window.getSize().x;
    //float ey = std::rand() % m_window.getSize().y;
    float ex = 100.0f, ey = 100.0f;
    e->cTransform->pos = { ex, ey };
}

void Scene_Play::update() {
    sEnemySpawner();
    m_currentFrame++;
    m_entities.update();
}

} /* namespace game_2d */