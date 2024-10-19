#include "Window.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include "Shader.h"

Window::Window(const unsigned int width, const unsigned int height, const char* title)
    : m_width(width), m_height(height), m_title(title) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    // Set OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a new window
    glfwWindow = glfwCreateWindow(static_cast<int>(m_width), static_cast<int>(m_height), m_title, nullptr, nullptr);
    if (!glfwWindow) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(glfwWindow);
}

Window::~Window() {
    glfwTerminate();
}

bool WindowManager::WindowIsActive() {
    return !glfwWindowShouldClose(WindowInstance->glfwWindow);
}

Window* WindowManager::WindowInstance = nullptr;

void WindowManager::Init(const unsigned int width, const unsigned int height, const char* title) {
    if (WindowInstance != nullptr) return;
    WindowInstance = new Window(width, height, title);
}

void WindowManager::Terminate() {
    WindowInstance->~Window();
    delete WindowInstance;
}

void WindowManager::UpdateWindow() {
    glfwSwapBuffers(WindowInstance->glfwWindow);
    glfwPollEvents();
}
