// ReSharper disable CppUnusedIncludeDirective
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.h"

class Window {
public:
    GLuint shader_program;

    Window(uint16_t width, uint16_t height, const char* title, bool vSync);
    ~Window();

    void BeginRendering() const;

    void EndRendering() const;

    [[nodiscard]] bool IsActive() const;
private:
    uint16_t m_width, m_height;
    const char* m_title;
    GLFWwindow* m_window;
};
