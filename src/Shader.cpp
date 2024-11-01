#include "Shader.h"

#include <fstream>
#include <iostream>

#include <GL/glew.h>

#include "Renderer.h"

std::string Shader::LoadShader(const std::string &filepath) {
    std::fstream file(filepath, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader file " << filepath << '\n';
        return {0};
    }

    std::string contents;

    std::string line;
    while (getline(file, line)) {
        contents.append(line + '\n');
    }

    return contents;
}

unsigned int Shader::CompileShader(const unsigned int type, const std::string &source) {
    const unsigned int id = glCreateShader(type);
    const char *sourceCString = source.c_str();
    glShaderSource(id, 1, &sourceCString, nullptr);
    glCompileShader(id);

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        const auto message = (char *) alloca(length);
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << message << '\n';
        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource) {
    // Shader Compilation
    const unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    const unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    // Program Creation
    const unsigned int shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);
    glValidateProgram(shader);

    // Cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shader;
}

Shader::Shader(const std::string &vertShaderfilepath, const std::string &fragShaderfilepath) {
    m_RendererID = CreateShader(LoadShader(vertShaderfilepath),
                                LoadShader(fragShaderfilepath));
}

Shader::Shader(Shader &&shader) noexcept {
    glDeleteProgram(m_RendererID);
    m_RendererID = shader.m_RendererID;
    shader.m_RendererID = 0;
}

Shader &Shader::operator=(Shader &&shader) noexcept {
    glDeleteProgram(m_RendererID);
    m_RendererID = shader.m_RendererID;
    shader.m_RendererID = 0;
    return *this;
}

Shader::~Shader() {
    glDeleteProgram(m_RendererID);
}

void Shader::Bind() const {
    glUseProgram(m_RendererID);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

void Shader::SetUniform4f(const std::string &name, const float v1, const float v2, const float v3,
                          const float v4) const {
    const auto location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniform4f(location, v1, v2, v3, v4);
}

unsigned int Shader::GetID() const {
    return m_RendererID;
}

int Shader::GetUniformLocation(const std::string &name) {
    if (m_UniformLocationCache.contains(name)) {
        return m_UniformLocationCache.at(name);
    }

    const int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1) {
        std::cerr << "Failed to get uniform location " << name << '\n';
    }
    m_UniformLocationCache[name] = location;

    return location;
}
