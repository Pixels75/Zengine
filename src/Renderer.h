#pragma once

#include <csignal>
#include <GL/glew.h>
#include <iostream>

#define ASSERT(x, m) if (!(x)) {\
        std::cout << "Assertion Failed: " << m << std::endl;\
        raise(SIGTRAP);\
    }

class Renderer {
public:
    static GLuint Shader;

    static void Init(bool vSync);
    static void Terminate();

    static void ClearColorBuffer();
};
