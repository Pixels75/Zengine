#include "Renderer.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

Shader Renderer::ActiveShader;

void Renderer::Init(const bool vSync) {
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

    // Load and set shaders
    ActiveShader = Shader("../res/shaders/vertex_shader.vert", "../res/shaders/fragment_shader.frag");
    ActiveShader.Bind();
}

const Shader& Renderer::GetActiveShader() {
    return ActiveShader;
}

void Renderer::ClearColorBuffer() {
    glClear(GL_COLOR_BUFFER_BIT);
}
