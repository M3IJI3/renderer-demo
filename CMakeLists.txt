cmake_minimum_required(VERSION 3.31)
project(renderer_demo)

set(CMAKE_CXX_STANDARD 20)

add_executable(renderer_demo src/main.cpp
        src/math/vec3.cpp
        src/math/vec3.h
        src/math/vec4.cpp
        src/math/vec4.h
        src/test/case.cpp
        src/test/case.h
        src/math/mat4.cpp
        src/math/mat4.h
        src/framebuffer.h)
