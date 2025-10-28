#ifndef __SCENE_RECORDS_H
#define __SCENE_RECORDS_H
#include "Scene.h"
#include "EntityManager.h"
#include "Action.h"
#include <iostream>
#include <array>
#include "Components/CButton.h"

namespace game_2d {
    
class Scene_Records : public Scene {

    sf::Font            m_font;
    std::vector<CButton> buttons;
    std::array<int, 4> records;
    int curr_text = 0;

public:
    Scene_Records(GameEngine *game);
    void sRender() override;
    void update() override;
    void sDoAction(Action action) override;
};

} /* namespace game_2d */

#endif /* __SCENE_RECORDS_H */