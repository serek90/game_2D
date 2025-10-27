#ifndef __SCENE_PLAY_H
#define __SCENE_PLAY_H
#include "Scene.h"
#include "EntityManager.h"
#include "Action.h"
#include <iostream>

namespace game_2d {
    
class Scene_Play : public Scene {

    sf::Font            m_font;
    sf::Text            m_text;
    int                 m_score = 0;
    EntityManager       m_entities;
    const size_t        m_enemySpawnTime = 24;
    sf::Clock           m_clock;
    std::shared_ptr<Entity> m_player;

    void borderCollision(std::string str);
    void spawnPlayer();
    void spawnEnemy();
    void spawnBullet();

public:
    Scene_Play(GameEngine *game);
    void sRender() override;
    void update() override;
    void sDoAction(Action action) override;

    /* Systems */
    void sEnemySpawner();
    void sMovement();
    void sCollision();
};

} /* namespace game_2d */


#endif /* __SCENE_PLAY_H */