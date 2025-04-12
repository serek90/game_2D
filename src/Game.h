#ifndef __GAME_H
#define __GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"

namespace game_2d {
    class Game {
        const int windowWidth = 640;
        const int windowHeight = 480;
        sf::RenderWindow window;
        EntityManager entityManager;
        void sRender();
        void sCollision();
        void sUserInput();
    public:
        Game() : window(sf::VideoMode(windowWidth, windowHeight), "SFML_works") {
            window.setFramerateLimit(60);
         }
        void run();

        // Systems
        void sMovement() {}
        void sEnemySpawner() {}
    };
}


#endif /* __GAME_H */