#include "Scene_Menu.h"

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

    int ctr = 0;
    for(auto &t : m_text) {
        t.setFont(m_font);
        t.setCharacterSize(40);
        t.setFillColor(sf::Color(255,255,255));
        t.setPosition(200, ctr * 60);
        t.setString("points: ");
        ctr++;
    }
    m_text.at(0).setString("New Game");
    m_text.at(1).setString("Records");
    m_text.at(2).setString("Replay");
    m_text.at(3).setString("Quit");

}

void Scene_Menu::sRender() {

    m_game->window().clear(sf::Color::Black);

    for(auto &t : m_text)
        t.setFillColor(sf::Color(255,255,255));
    m_text.at(curr_text).setFillColor(sf::Color(255,0,0));
    for(auto &t : m_text)
        m_game->window().draw(t);
 
    m_game->window().display();
}

void Scene_Menu::sDoAction(Action action) {
    if(action.type() == action_t::START) {
        if(action.name() == "player_move_up")
            curr_text = curr_text ? --curr_text : m_text.size() - 1;
        else if(action.name() == "player_move_down")
            curr_text = curr_text < m_text.size() - 1 ? ++curr_text : 0;
        else if(action.name() == "next_scene")
            m_game->changeScene("Scene_Play");   
    }
}

void Scene_Menu::update() {

}

} /* namespace game_2d */