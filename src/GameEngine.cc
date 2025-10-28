#include "GameEngine.h"
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include "Scene_Play.h"
#include "Scene_Menu.h"


namespace game_2d {

GameEngine::GameEngine(const std:: string &path) {

    m_window.create(sf::VideoMode(600, 800), "game_2d");
    m_window.setFramerateLimit(60);

    changeScene("Scene_Menu");
}

void GameEngine::run() {

    while (m_window.isOpen()) {
        update();
        sUserInput();
    }
}

void GameEngine::changeScene(std::string scene_name) {
    m_currentScene = scene_name;
    if(m_currentScene == "Scene_Menu")
        scenes[m_currentScene] = std::make_shared<Scene_Menu>(this);
    if(m_currentScene == "Scene_Play")
        scenes[m_currentScene] = std::make_shared<Scene_Play>(this);
}

void GameEngine::sUserInput() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
            return;
        }

        if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if(currentScene()->getActionMap().find(event.key.code) == currentScene()->getActionMap().end())
                continue;
            const action_t action_type = event.type == sf::Event::KeyPressed ? action_t::START : action_t::END;
            currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key.code), action_type) );
        }
    }
}

void GameEngine::update() {
    scenes[m_currentScene]->simulate(0);
}

}