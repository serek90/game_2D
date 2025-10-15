#ifndef __SCENE_PLAY_H
#define __SCENE_PLAY_H
#include "Scene.h"
#include "EntityManager.h"
#include <iostream>

namespace game_2d {
    
class Scene_Play : public Scene {

void spawnEnemy();
EntityManager       m_entities;
const size_t        m_enemySpawnTime = 24;
sf::Clock           m_clock;

public:
Scene_Play(GameEngine *game) { m_game = game; }
void sRender() override;
void update() override;

void sEnemySpawner();
void sMovement();

};

} /* namespace game_2d */


#endif /* __SCENE_PLAY_H */