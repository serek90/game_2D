#ifndef __SCENE_H
#define __SCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "GameEngine.h"

namespace game_2d {
    
class GameEngine;

class Scene {

protected:
  GameEngine *m_game;
  int m_currentFrame;
  std::map<int, std::string> m_actionMap;
  bool m_paused;
  bool m_hasEnded;

public:
  virtual void update() = 0;
  //void sDoAction(Action action) = 0;
  virtual void sRender() = 0;

  void simulate(int) {
    update(); 
    sRender();
  }
  //void doAction(Action action) {}
  //void registerAction(Action action) {}

};

} /* namespace game_2d */


#endif /* __SCENE_H */