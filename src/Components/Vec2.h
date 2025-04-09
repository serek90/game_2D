#ifndef __VEC2_H
#define __VEC2_H

#include <cmath>


namespace game_2d {
    class Vec2
    {
        float x;
        float y;
    public:
        Vec2(float xin, float yin) : x{xin}, y{yin} {}

        Vec2 operator + (const Vec2 &rhs) const;
        Vec2 operator - (const Vec2 &rhs) const;
        Vec2 operator * (const float val) const;
        Vec2 operator / (const float val) const;

        void operator += (const Vec2 &rhs);
        void operator -= (const Vec2 &rhs);
        void operator *= (const float val);
        void operator /= (const float val);

        bool operator == (const Vec2 &rhs) const;
        bool operator != (const Vec2 &rhs) const;

        Vec2& add(const Vec2& v);
        Vec2 &scale(float s);
        Vec2& rotate(float deg);

        float dist(const Vec2& v) const;
    };
}


#endif /* __VEC2_H */