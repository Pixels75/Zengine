#include <GL/glew.h>

#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Objects/VertexArrayObject.h"
#include "Objects/BufferObject.h"

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 640
#define WINDOW_TITLE  ""
#define VSYNC         true

void UpdateColor();

int main() {
    // Initialize vertex data
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, // index 0
         0.5f, -0.5f, 1.0f, 0.0f, // index 1
         0.5f,  0.5f, 1.0f, 1.0f, // index 2
        -0.5f,  0.5f, 0.0f, 1.0f  // index 3
    };

    // Initialize index data
    unsigned int indices[] = {
        0, 1, 2, // Triangle 1
        2, 3, 0  // Triangle 2
    };

    // Create a new window
    WindowManager::Init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    Renderer::Init(VSYNC);

    // Declare and initialize buffers
    const auto vao = VertexArrayObject();
    const auto vbo = VertexBufferObject(vertices, 16, GL_STATIC_DRAW);
    const auto ibo = IndexBufferObject(indices, 6, GL_STATIC_DRAW);

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    vao.AddVertexBuffer(vbo, layout);

    const auto tex = Texture("../res/textures/checkerboard.png");
    tex.Bind();

    // Main Loop
    while (WindowManager::WindowIsActive()) {
        Renderer::ClearColorBuffer();

        UpdateColor();

        Renderer::Render(vao, ibo);
        WindowManager::UpdateWindow();
    }

    // Close window
    WindowManager::Terminate();
}

void UpdateColor() {
    Renderer::GetActiveShader().SetUniform4f("u_Color", 1.0, 0.0, 0.0, 1.0);

    static float red = 1.0f;
    static float blue = 0.0f;
    static float i = -0.01f;

    i = red > 1.0f || red < 0.0f ? -i : i;

    red += i;
    blue -= i;

    Renderer::GetActiveShader().SetUniform4f("u_Color", red, 0.0, blue, 1.0);
}
