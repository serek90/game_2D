#include <iostream>
#include "../src/Vec2.h"


#define TEST_EQ (x, y) x == y

int main()
{

  Vec2 vec1(10, 20);
  Vec2 vec2(20, 30);

  vec1 += vec2;
  std::cout << "Vector :" <<  vec1.x << "," << vec1.y << std::endl;
  return 0;
}