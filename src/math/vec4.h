//
// Created by major on 2025-06-21.
//

#pragma once
#include "vec3.h"

struct Vec4
{
    float x, y, z, w;

    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(const float _x, const float _y, const float _z, const float _w = 1.0f) : x(_x), y(_y), z(_z), w(_w) {}

    // 齐次除法 转换到 Vec3
    [[nodiscard]] Vec3 toVec3() const
    {
        // 避免除以0
        if (w == 0.0f) return { x, y, z };
        return { x / w , y / w , z / w  };
    }

    // 矩阵乘 Vec4
    Vec4 operator*(const float s) const
    {
        return { x * s, y * s, z * s, w * s };
    }
};
