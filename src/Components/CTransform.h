#ifndef __TRANSFORM_H
#define __TRANSFORM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "Vec2.h"

namespace game_2d {
  class CTransform
  {
  public:
    Vec2 pos = { 0, 0 };
    Vec2 velocity = { 0, 0 };
    Vec2 direction = { 0, 0 };
    float angle;

    CTransform(const Vec2 &p, const Vec2 &v, float ang)
      : pos{p}, velocity{v}, angle{ang} {}

    };
}

#endif /* __TRANSFORM_H */