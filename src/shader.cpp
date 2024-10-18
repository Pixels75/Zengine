#include "shader.h"

#include <fstream>
#include <iostream>

std::string Shader::LoadShader(const char *filepath) {
    std::fstream file(filepath, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filepath << '\n';
        return {0};
    }

    std::string contents;

    std::string line;
    while (getline(file, line)) {
        contents.append(line + '\n');
    }

    return contents;
}

GLuint Shader::CompileShader(const GLuint type, const std::string& source) {
    const GLuint id = glCreateShader(type);
    const char* sourceCString = source.c_str();
    glShaderSource(id, 1, &sourceCString, nullptr);
    glCompileShader(id);

    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = static_cast<char*>(alloca(length));
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << message << '\n';
        glDeleteShader(id);
        return 0;
    }

    return id;
}

GLuint Shader::CreateShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
    // Shader Compilation
    const GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    const GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    // Program Creation
    const GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glValidateProgram(program);

    // Cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}