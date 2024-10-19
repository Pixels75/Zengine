#pragma once

#include <string>
#include <GL/glew.h>

class Shader {
public:
    static std::string LoadShader(const char* filepath);

    static GLuint CompileShader(GLuint type, const std::string& source);

    static GLuint CreateShader(const std::string& vertexShaderSource,
                               const std::string& fragmentShaderSource);
};