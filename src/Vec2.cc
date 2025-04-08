#include "Vec2.h"


namespace game_2d {

    Vec2 Vec2::operator + (const Vec2 &rhs) const {
        Vec2 vec(rhs.x + x, rhs.y + y);
        return vec;
    }

    Vec2 Vec2::operator - (const Vec2 &rhs) const {
        Vec2 vec(rhs.x - x, rhs.y - y);
        return vec;
    }

    Vec2 Vec2::operator * (const float val) const {
        Vec2 vec(x * val, y * val);
        return vec;
    }

    Vec2 Vec2::operator / (const float val) const {
        Vec2 vec(x / val, y / val);
        return vec;
    }

    void Vec2::operator += (const Vec2 &rhs) {
        x += rhs.x;
        y += rhs.y;
    }

    void Vec2::operator -= (const Vec2 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
    }

    void Vec2::operator *= (const float val) {
        x *= val;
        y *= val;
    }

    void Vec2::operator /= (const float val) {
        x /= val;
        y /= val;
    }

    float Vec2::dist(const Vec2& v) const {
        return sqrtf((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
    }

    bool Vec2::operator == (const Vec2 &rhs) const {
        return (x == rhs.x && y == rhs.y);
    }

    bool Vec2::operator != (const Vec2 &rhs) const {
        return (x != rhs.x || y != rhs.y);
    }

    Vec2& Vec2::scale(float s) {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2& Vec2::rotate(float deg) {
        return *this;
    }
}
    