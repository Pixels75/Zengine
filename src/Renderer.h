#pragma once

#include <csignal>
#include <iostream>

#include "Shader.h"

#define ASSERT(x, m) if (!(x)) {\
        std::cout << "Assertion Failed: " << m << std::endl;\
        raise(SIGTRAP);\
    }

class Renderer {
public:
    static void Init(bool vSync);

    static const Shader& GetActiveShader();

    static void ClearColorBuffer();
private:
    static Shader ActiveShader;
};
