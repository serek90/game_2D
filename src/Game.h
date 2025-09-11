#ifndef __GAME_H
#define __GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"

struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig  { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

namespace game_2d {
    class Game {
        const int windowWidth = 640;
        const int windowHeight = 480;

        sf::RenderWindow window;
        EntityManager entityManager;
        bool m_paused = false;

        std::shared_ptr<Entity> player;

        size_t m_frame_ctr = 0;

        void spawnBullet();
        void spawnPlayer();
        void spawnEnemy();

        void sEnemySpawner();

        // Systems
        void sRender();
        void sCollision();
        void sUserInput();
        void sMovement();

        //ToDo: Make it using radius component
        void borderCollision(std::string str);
    public:
        Game() : window(sf::VideoMode(windowWidth, windowHeight), "SFML_works") {
            window.setFramerateLimit(60);
         }
        void run();

    };
}


#endif /* __GAME_H */