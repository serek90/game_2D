#ifndef __CBUTTON_H
#define __CBUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Scene.h"

namespace game_2d {

struct CButton {
    sf::Text text;
    std::string name;
    std::string scene;
    CButton(std::string n, std::string sc) { 
        scene = sc; name = n;
        text.setString(name);}
};
}

#endif /* __CBUTTON_H */