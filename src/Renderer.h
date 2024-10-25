#pragma once

#include <csignal>
#include <iostream>

#include "Shader.h"
#include "Objects/BufferObject.h"
#include "Objects/VertexArrayObject.h"

#define ASSERT(x, m) if (!(x)) {\
        std::cout << "Assertion Failed: " << m << std::endl;\
        raise(SIGTRAP);\
    }

class Renderer {
public:
    static void Init(bool vSync);

    static void Init(const std::string &vertShaderPath, const std::string &fragShaderPath, bool vSync);

    static const Shader &GetActiveShader();

    static void SetActiveShader(Shader &&shader);

    static void ClearColorBuffer();

    static void Render(const VertexArrayObject &vao, const IndexBufferObject &ibo);

private:
    static Shader ActiveShader;
};
