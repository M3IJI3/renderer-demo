//
// Created by major on 2025-06-21.
//

#pragma once
#include "vec4.h"

struct Mat4
{
    float m[4][4];

    // 创建单位矩阵
    static Mat4 identity()
    {
        Mat4 I{};
        for (int i = 0 ; i < 4 ; i++)
            for (int j = 0 ; j < 4 ; j++)
                I.m[i][j] = (i == j) ? 1.0f : 0.0f;
        return I;
    }

    // 平移矩阵
    static Mat4 translate(const float tx, const float ty, const float tz)
    {
        Mat4 T = identity();
        T.m[0][3] = tx;
        T.m[1][3] = ty;
        T.m[2][3] = tz;
        return T;
    }

    // 矩阵乘法
    Mat4 operator*(const Mat4& o) const
    {
        Mat4 r{};
        for (int i = 0 ; i < 4 ; i++){
            for (int j = 0 ; j < 4 ; j++){
                r.m[i][j] = 0.0f;
                for (int k = 0 ; k < 4 ; k++){
                    r.m[i][j] += m[i][k] * o.m[k][j];
                }
            }
        }
        return r;
    }

    // 矩阵 x 向量
    Vec4 operator*(const Vec4& o) const
    {
        Vec4 r;
        r.x = m[0][0]*o.x + m[0][1]*o.y + m[0][2]*o.z + m[0][3]*o.w;
        r.y = m[1][0]*o.x + m[1][1]*o.y + m[1][2]*o.z + m[1][3]*o.w;
        r.z = m[2][0]*o.x + m[2][1]*o.y + m[2][2]*o.z + m[2][3]*o.w;
        r.w = m[3][0]*o.x + m[3][1]*o.y + m[3][2]*o.z + m[3][3]*o.w;
        return r;
    }
};
