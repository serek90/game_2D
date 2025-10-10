#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "Scene.h"
#include "Scene_Play.h"

namespace game_2d {

class Scene;

class GameEngine {
    sf::RenderWindow    m_window;
    std::map<std::string, std::shared_ptr<Scene>> scenes;
    //Assets m_assets;
    std::string m_currentScene;
    bool m_running;

public:
    GameEngine(const std:: string &path);
    void run();
    void update();
    void quit() {}
    void changeScene(std::string scene_name);
    Scene * currentScene() {}
    //Assets & getAssets() {}
    sf::RenderWindow & window() { return m_window; }
    void sUserInput();
};

} /* namespace game_2d */


#endif /* __GAME_H */