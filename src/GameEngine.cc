#include "GameEngine.h"
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include "Scene_Play.h"
#include "Scene_Menu.h"
#include "Scene_Records.h"


namespace game_2d {

GameEngine::GameEngine(const std:: string &path) {

    m_window.create(sf::VideoMode(600, 800), "game_2d");
    m_window.setFramerateLimit(60);

    changeScene("Scene_Menu");
    m_running = true;
}

void GameEngine::run() {

    while (m_running) {
        update();
        sUserInput();
        if(!m_window.isOpen())
            m_running = false;
    }
}

void GameEngine::changeScene(std::string scene_name) {
    m_currentScene = scene_name;
    if(m_currentScene == "Scene_Menu")
        scenes[m_currentScene] = std::make_shared<Scene_Menu>(this);
    else if(m_currentScene == "Scene_Play")
        scenes[m_currentScene] = std::make_shared<Scene_Play>(this);
    else if(m_currentScene == "Scene_Records")
        scenes[m_currentScene] = std::make_shared<Scene_Records>(this);
    else
        m_running = false;
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