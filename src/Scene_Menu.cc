#include "Scene_Menu.h"
#include "Scene_Play.h"
#include "Scene_Records.h"

namespace game_2d {

Scene_Menu::Scene_Menu(GameEngine *game) {
    m_game = game;

    registerAction(sf::Keyboard::Up,    "player_move_up");
    registerAction(sf::Keyboard::Down,  "player_move_down");
    registerAction(sf::Keyboard::Left,  "player_move_left");
    registerAction(sf::Keyboard::Right, "player_move_right");
    registerAction(sf::Keyboard::W,     "player_move_shoot");
    registerAction(sf::Keyboard::Enter, "next_scene");

    if (!m_font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Font loading error\n";


    buttons.push_back(CButton("New Game", "Scene_Play"));
    buttons.push_back(CButton("Records", "Scene_Records"));
    buttons.push_back(CButton("Quit", "None"));

    for(auto i = 0; i < buttons.size(); i++) {
        buttons[i].text.setFont(m_font);
        buttons[i].text.setCharacterSize(40);
        buttons[i].text.setFillColor(sf::Color(255,255,255));
        buttons[i].text.setPosition(200, i * 60);
    }
}

void Scene_Menu::sRender() {

    m_game->window().clear(sf::Color::Black);

    for(auto &b : buttons)
        b.text.setFillColor(sf::Color(255,255,255));
    buttons.at(curr_text).text.setFillColor(sf::Color(255,0,0));
    for(auto &b : buttons)
        m_game->window().draw(b.text);
 
    m_game->window().display();
}

void Scene_Menu::sDoAction(Action action) {
    if(action.type() == action_t::START) {
        if(action.name() == "player_move_up")
            curr_text = curr_text ? --curr_text : buttons.size() - 1;
        else if(action.name() == "player_move_down")
            curr_text = curr_text < buttons.size() - 1 ? ++curr_text : 0;
        else if(action.name() == "next_scene")
            m_game->changeScene(buttons[curr_text].scene);
    }
}

void Scene_Menu::update() {

}

} /* namespace game_2d */