//
// Created by major on 2025-06-24.
//

# pragma once

#include <cstdint>
#include <ios>
#include <iosfwd>
#include <limits>
#include <vector>
#include <fstream>

struct FrameBuffer
{
    int width, height;
    std::vector<uint8_t> color;   // 每像素 3 字节 RGB
    std::vector<float>   depth;   // 每像素深度值

    FrameBuffer(const int w, const int h) :
        width(w), height(h),
        color(w * h * 3, 0),
        depth(w * h, std::numeric_limits<float>::infinity()) {}

    // 在 (x,y) 处根据深度 z 写入颜色 (r, g, b)
    void setPixel(int x, int y, float z, uint8_t r, uint8_t g, uint8_t b)
    {
        int idx = y * width + x;
        if (x<0 || x>=width || y<0 || y>=height) return;
        if (z > depth[idx])
        {
            depth[idx] = z;
            int c = idx*3;
            color[c+0] = r;
            color[c+1] = g;
            color[c+2] = b;
        }
    }

    // 把 color 写成一个 PPM 文件
    void writePPM(const char* filename)
    {
        std::ofstream ofs(filename, std::ios::binary);
        ofs << "P6\n" << width << " " << height << "\n255\n";
        ofs.write(reinterpret_cast<char*>(color.data()), color.size());
        ofs.close();
    }
};
