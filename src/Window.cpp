#include "Window.h"

#include <cassert>
#include <iostream>
#include <GLFW/glfw3.h>

#include "Shader.h"

Window::Window(const uint16_t width, const uint16_t height, const char *title, const bool vSync)
    : m_width(width), m_height(height), m_title(title) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a new window
    m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
    if (!m_window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);

    if (vSync)
        glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwTerminate();
        return;
    }

    // Print OpenGL and GLSL version
    std::cout << "OpenGL Version - " << glGetString(GL_VERSION) << '\n';
    std::cout << "GLSL Version   - " << glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n';

    shader_program = Shader::CreateShaderProgram(Shader::LoadShader("../res/vertex_shader.vert"  ),
                                            Shader::LoadShader("../res/fragment_shader.frag"));
    glUseProgram(shader_program);
}

Window::~Window() {
    glDeleteProgram(shader_program);
    glfwTerminate();
}

void Window::BeginRendering() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::EndRendering() const {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

bool Window::IsActive() const {
    return !glfwWindowShouldClose(m_window);
}