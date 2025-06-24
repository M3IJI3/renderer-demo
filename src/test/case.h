//
// Created by major on 2025-06-21.
//

#pragma once
#include <iostream>

#include "../framebuffer.h"
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

inline void testcase4()
{
    FrameBuffer fb(800, 600);

    for (int i = 0 ; i < 800*600 ; i++)
    {
        fb.color[i*3 + 0] = 50;
        fb.color[i*3 + 1] = 50;
        fb.color[i*3 + 2] = 50;
    }

    // 定义一个简单的三角形（物体空间顶点）
    Vec3 tri[3] = {
        { -0.5f, -0.5f, 0.0f },
        {  0.5f, -0.5f, 0.0f },
        {  0.0f,  0.5f, 0.0f }
    };

    // 1. 模型矩阵：这里只做平移
    const Mat4 Model = Mat4::translate(0.0f, 0.0f, 0.0f);

    // 2. 视图矩阵：相机在 (0,0,2) 看向原点
    const Mat4 View = Mat4::lookAt(
      Vec3{0,0,2},  // eye
      Vec3{0,0,0},  // center
      Vec3{0,1,0}   // up
    );

    // 3. 投影矩阵：45° 视场，宽高比 800/600，近平面 0.1，远平面 100
    const Mat4 Projection = Mat4::perspective(
      45.0f * 3.1415926f / 180.0f,
      800.0f / 600.0f,
      0.1f,
      100.0f
    );

    // 合成 MVP
    const Mat4 MVP = Projection * View * Model;

    // 屏幕尺寸
    const float width = 800.0f, height = 600.0f;

    // 对每个顶点做变换
    for(int i = 0; i < 3; i++) {
        Vec4 v = Vec4(tri[i].x, tri[i].y, tri[i].z, 1.0f);
        Vec4 clip = MVP * v;              // 裁剪空间
        Vec3 ndc = clip.toVec3();         // 归一化设备坐标 (-1~1)
        // 视口变换到屏幕坐标
        const int   x = int((ndc.x * 0.5f + 0.5f) *  width);
        const int   y = int((ndc.y * 0.5f + 0.5f) * height);
        const float z = ndc.z;

        const uint8_t r = (i==0) ? 255 : 0;
        const uint8_t g = (i==1) ? 255 : 0;
        const uint8_t b = (i==2) ? 255 : 0;
        fb.setPixel(x, y, z, r, g, b);
    }

    fb.writePPM("output.ppm");
    std::cout << "Wrote out.ppm, open it to see three colored points.\n";
}
