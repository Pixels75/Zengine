#include <GL/glew.h>

#include "Window.h"
#include "Renderer.h"
#include "Objects/VertexArrayObject.h"
#include "Objects/BufferObject.h"

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480
#define WINDOW_TITLE  ""
#define VSYNC         true

int main() {
    // Initialize vertex data
    float vertices[] = {
        -0.5f, -0.5f, // index 0
         0.5f, -0.5f, // index 1
         0.5f,  0.5f, // index 2
        -0.5f,  0.5f  // index 3
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
    const auto vao = VertexArrayObject ();
    const auto vbo = VertexBufferObject(vertices, 8, GL_STATIC_DRAW);
    const auto ibo = IndexBufferObject (indices,  6, GL_STATIC_DRAW);

    VertexBufferLayout layout;
    layout.Push<float>(2);
    vao.AddVertexBuffer(vbo, layout);

    Renderer::GetActiveShader().SetUniform4f("u_Color", 1.0, 0.0, 0.0, 1.0);

    float red = 1.0f;
    float blue = 0.0f;
    float i = 0.01f;

    // Main Loop
    while (WindowManager::WindowIsActive()) {
        Renderer::ClearColorBuffer();

        i = red > 1.0f || red < 0.0f ? -i : i;

        red  -= i;
        blue += i;

        Renderer::GetActiveShader().SetUniform4f("u_Color", red, 0.0, blue, 1.0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        WindowManager::UpdateWindow();
    }

    // Close window
    WindowManager::Terminate();
}