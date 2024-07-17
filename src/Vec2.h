#ifndef __VEC2_H
#define __VEC2_H

class Vec2
{

public:
    float x;
    float y;

    Vec2() {}
    Vec2(float xin, float yin) : x{xin}, y{yin} {}


    Vec2 operator + (const Vec2 &rhs) const
    {
        Vec2 vec(rhs.x + x, rhs.y + y);
        return vec;
    }

    void operator += (const Vec2 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
    }

    Vec2& add(const Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2 &scale(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2& rotate(float deg)
    {
        return *this;
    }

    float dist(const Vec2& v) const
    {
        return sqrtf((v.x -x ) * (v.x - x) + (v.y - y) * (v.y - y));
    }
};


#endif /* __VEC2_H */