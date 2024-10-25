#include "Renderer.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

Shader Renderer::ActiveShader;

void Renderer::Init(bool vSync) {
    Init("../res/shaders/vertex_shader.vert",
         "../res/shaders/fragment_shader.frag",
         vSync);
}

void Renderer::Init(const std::string &vertShaderPath, const std::string &fragShaderPath, const bool vSync) {
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
    SetActiveShader(Shader(vertShaderPath, fragShaderPath));
    ActiveShader.Bind();
}

const Shader &Renderer::GetActiveShader() {
    return ActiveShader;
}

void Renderer::SetActiveShader(Shader &&shader) {
    ActiveShader = std::move(shader);
}

void Renderer::ClearColorBuffer() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Render(const VertexArrayObject &vao, const IndexBufferObject &ibo) {
    vao.Bind();
    ibo.Bind();
    ActiveShader.Bind();

    glDrawElements(GL_TRIANGLES, (int) ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
}
