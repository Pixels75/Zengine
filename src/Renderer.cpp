#include "Renderer.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Window.h"

GLuint Renderer::Shader;

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
    Shader = Shader::CreateShader(Shader::LoadShader("../res/vertex_shader.vert"  ),
                                  Shader::LoadShader("../res/fragment_shader.frag"));
    glUseProgram(Shader);
}

void Renderer::Terminate() {
    glDeleteProgram(Shader);
}

void Renderer::ClearColorBuffer() {
    glClear(GL_COLOR_BUFFER_BIT);
}