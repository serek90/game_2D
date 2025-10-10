#include "GameEngine.h"
#include <memory>
#include <sstream>
#include <string>
#include <fstream>


namespace game_2d {

GameEngine::GameEngine(const std:: string &path) {

    m_window.create(sf::VideoMode(600, 800), "game_2d");
    m_window.setFramerateLimit(60);

    changeScene("Scene_play");
}

void GameEngine::run() {

    while (m_window.isOpen()) {
        update();
        sUserInput();
    }
}

void GameEngine::changeScene(std::string scene_name) {
    m_currentScene = scene_name;
    scenes[m_currentScene] = std::make_shared<Scene_Play>(this);
}

void GameEngine::sUserInput() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
            return;
        }
    }
}

void GameEngine::update() {
    scenes[m_currentScene]->simulate(0);
}

}