#ifndef __SCENE_H
#define __SCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "GameEngine.h"
#include "Action.h"

namespace game_2d {
    
class GameEngine;

using actionMap = std::map<int, std::string>;

class Scene {

protected:
  GameEngine *m_game;
  int m_currentFrame;
  actionMap m_actionMap;
  bool m_paused;
  bool m_hasEnded;

public:
  virtual void update() = 0;
  virtual void sDoAction(Action action) = 0;
  virtual void sRender() = 0;

  void simulate(int) {
    update(); 
    sRender();
  }
  void doAction(Action action) { sDoAction(action); }
  void registerAction(int key , std::string action_name) { m_actionMap[key] = action_name; }
  actionMap &getActionMap() { return m_actionMap; }

};

} /* namespace game_2d */


#endif /* __SCENE_H */