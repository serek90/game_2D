#ifndef __TRANSFORM_H
#define __TRANSFORM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "Vec2.h"

class CTransform
{
public:
  Vec2 pos = { 0, 0 };
  Vec2 velocity = { 0, 0 };

  CTransform() {}
  CTransform(const Vec2 &p, const Vec2 &v) : pos{p}, velocity{v} {}

};

#endif /* __TRANSFORM_H */