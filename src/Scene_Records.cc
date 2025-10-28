#include "Scene_Records.h"
#include "Scene_Menu.h"

namespace game_2d {

Scene_Records::Scene_Records(GameEngine *game) {
    m_game = game;

    registerAction(sf::Keyboard::Enter, "scene_back");

    if (!m_font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Font loading error\n";


    buttons.push_back(CButton("Back", "Scene_Menu"));

    for(auto i = 0; i < buttons.size(); i++) {
        buttons[i].text.setFont(m_font);
        buttons[i].text.setCharacterSize(40);
        buttons[i].text.setFillColor(sf::Color(255,255,255));
        buttons[i].text.setPosition(200, i * 60 + 300);
    }
}

void Scene_Records::sRender() {

    m_game->window().clear(sf::Color::Black);

    for(auto &b : buttons)
        b.text.setFillColor(sf::Color(255,255,255));
    buttons.at(curr_text).text.setFillColor(sf::Color(255,0,0));
    for(auto &b : buttons)
        m_game->window().draw(b.text);
 
    m_game->window().display();
}

void Scene_Records::sDoAction(Action action) {
    if(action.type() == action_t::START) {
        if(action.name() == "scene_back")
            m_game->changeScene(buttons[curr_text].scene);   
    }
}

void Scene_Records::update() {

}

} /* namespace game_2d */