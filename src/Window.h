// ReSharper disable CppUnusedIncludeDirective
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

class Window {
public:
    GLFWwindow* glfwWindow;

    Window(unsigned int width, unsigned int height, const char* title);
    ~Window();

private:
    unsigned int m_width, m_height;
    const char* m_title;
};

class WindowManager {
public:
    static Window* GetInstance();

    [[nodiscard]] static bool WindowIsActive();

    static void Init(unsigned int width, unsigned int height, const char* title);
    static void Terminate();

    static void UpdateWindow();
private:
    static Window* Instance;
};
