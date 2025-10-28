#ifndef __SCENE_MENU_H
#define __SCENE_MENU_H
#include "Scene.h"
#include "Scene_Play.h"
#include "EntityManager.h"
#include "Action.h"
#include <iostream>
#include <array>

namespace game_2d {
    
class Scene_Menu : public Scene {

    sf::Font            m_font;
    std::array<sf::Text, 4>   m_text;
    int curr_text = 0;
    std::vector<std::string> buttons = { "Load game", "New game", "Records", "Replay", "Quit"};

public:
    Scene_Menu(GameEngine *game);
    void sRender() override;
    void update() override;
    void sDoAction(Action action) override;
};

} /* namespace game_2d */


#endif /* __SCENE_PLAY_H */