//
// Created by major on 2025-06-21.
//

#pragma once
#include <complex>

struct Vec3
{
    float x, y, z;
    Vec3() : x(0), y(0), z(0) {}
    Vec3(const float _x, const float _y, const float _z) : x(_x), y(_y), z(_z) {}

    Vec3 operator+(const Vec3& o) const { return {x + o.x, y + o.y, z + o.z}; }
    Vec3 operator-(const Vec3& o) const { return {x - o.x, y - o.y, z - o.z}; }
    Vec3 operator*(const float o) const { return {x * o,     y * o,   z * o}; }


    [[nodiscard]] float dot (const Vec3& o) const { return x * o.x + y * o.y + z * o.z;   }
    [[nodiscard]] Vec3 cross(const Vec3& o) const
    {
        return {
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x
        };
    }

    [[nodiscard]] float length() const { return std::sqrt(dot(*this)); }
    [[nodiscard]] Vec3 normalize() const
    {
        const float L = length();
        return L > 0 ? (*this) * (1.0f / L) : Vec3();
    }
};
