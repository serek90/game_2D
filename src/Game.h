#ifndef __GAME_H
#define __GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"
#include <memory>

struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig  { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

namespace game_2d {
    
class Game {
    const int windowWidth = 640;
    const int windowHeight = 480;

    sf::RenderWindow    m_window;
    sf::Font            m_font;
    sf::Text            m_text;
    EntityManager       m_entities;
    bool                m_paused = false;
    int                 m_score = 0;
    size_t              m_frame_ctr = 0;
    const size_t        m_enemySpawnTime = 240;
    PlayerConfig        m_playerConfig;
    EnemyConfig         m_EnemyConfig;
    BulletConfig        m_BulletConfig;
    sf::Clock           m_clock;

    std::shared_ptr<Entity> m_player;

    void setPaused(bool paused);

    void spawnBullet();
    void spawnPlayer();
    void spawnEnemy();
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2 &mousePos);
    void spawnSmallEnemies(std::shared_ptr<Entity> entity);
    void spawnSpecialWeapon(std::shared_ptr<Entity> entity);
    void spawnText();

    // Systems
    void sRender();
    void sCollision();
    void sUserInput();
    void sMovement();
    void sLifeSpan();
    void sEnemySpawner();


   //ToDo: Make it using radius component
    void borderCollision(std::string str);

public:
    Game(const std:: string &path);
    void run();

};

} /* namespace game_2d */


#endif /* __GAME_H */