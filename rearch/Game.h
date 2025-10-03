#ifndef __GAME_H
#define __GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

namespace game_2d {
    
class Game {
    sf::RenderWindow    m_window;
    sf::Font            m_font;
    sf::Text            m_text;


public:
    Game(const std:: string &path) {}
    void run();

};

} /* namespace game_2d */


#endif /* __GAME_H */