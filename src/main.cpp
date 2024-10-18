#include <GL/glew.h>

#include <cassert>

#include "buffer_object.h"
#include "window.h"

int main() {
    // Create a new window
    const Window window(640, 480, "", true);

    float vertices[] = {
        -0.5f, -0.5f, // index 0
         0.5f, -0.5f, // index 1
         0.5f,  0.5f, // index 2
        -0.5f,  0.5f  // index 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    auto vbo = VertexBufferObject(vertices, 8, GL_STATIC_DRAW);
    auto ibo = IndexBufferObject (indices,  6, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

    const int location = glGetUniformLocation(window.shader_program, "u_Color");
    assert(location != -1);
    glUniform4f(location, 1.0, 0.0, 0.0, 1.0);

    float red = 1.0f;
    float blue = 0.0f;
    float i = 0.01f;

    // Main Loop
    while (window.IsActive()) {
        window.BeginRendering();

        i = red > 1.0f || red < 0.0f ? -i : i;

        red  -= i;
        blue += i;

        glUniform4f(location, red, 0.0, blue, 1.0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        window.EndRendering();
    }
}