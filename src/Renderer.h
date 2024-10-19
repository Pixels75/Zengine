#pragma once

#include <GL/glew.h>

class Renderer {
public:
    static GLuint Shader;

    static void Init(bool vSync);
    static void Terminate();

    static void ClearBackground();
};
