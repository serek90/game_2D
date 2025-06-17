#ifndef __GAME_H
#define __GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"

namespace game_2d {
    class Game {
        const int windowWidth = 640;
        const int windowHeight = 480;
        std::shared_ptr<Entity> player;
        sf::RenderWindow window;
        EntityManager entityManager;
        bool m_paused = false;
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