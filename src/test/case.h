//
// Created by major on 2025-06-21.
//

#pragma once
#include <iostream>

#include "../math/mat4.h"
#include "../math/vec3.h"
#include "../math/vec4.h"

inline void testcase1()
{
    Vec3 a(1,2,3), b(4,5,6);
    Vec3 c = a + b;
    Vec3 d = b - a;
    float dp = a.dot(b);
    Vec3  cp = a.cross(b);
    Vec3  n  = Vec3(3,4,0).normalize();

    std::cout
      << "a+b = (" << c.x << "," << c.y << "," << c.z << ")\n"
      << "b-a = (" << d.x << "," << d.y << "," << d.z << ")\n"
      << "dot(a,b) = " << dp << "\n"
      << "cross(a,b) = (" << cp.x << "," << cp.y << "," << cp.z << ")\n"
      << "normalize(3,4,0) = (" << n.x << "," << n.y << "," << n.z << ")\n";
}

inline void testcase2()
{
    Vec4 p1(2, 10, 6, 2);
    Vec3 p1_3 = p1.toVec3();
    std::cout
      << "Vec4(2,10,6,2).toVec3() = ("
      << p1_3.x << "," << p1_3.y << "," << p1_3.z << ")\n";
}

// 测试 Mat4.identity()
inline void testcase3()
{
    Vec4 p(1,2,3,1);
    Mat4 I = Mat4::identity();
    Vec4 p2 = I * p;
    std::cout << "Identity * (1,2,3,1) = ("
              << p2.x << "," << p2.y << "," << p2.z << "," << p2.w << ")\n";

    // 测试平移
    Mat4 T = Mat4::translate(5, -3, 2);
    Vec4 p3 = T * p;
    std::cout << "Translate(5,-3,2) * (1,2,3,1) = ("
              << p3.x << "," << p3.y << "," << p3.z << "," << p3.w << ")\n";
}
