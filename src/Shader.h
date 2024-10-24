#pragma once

#include <string>
#include <unordered_map>

class Shader {
public:
    static std::string LoadShader(const std::string& filepath);
    static unsigned int CompileShader(unsigned int type, const std::string& source);
    static unsigned int CreateShader(const std::string& vertexShaderSource,
                      const std::string& fragmentShaderSource);

public:
    Shader() = default;
    Shader(const std::string& vertShaderFilePath, const std::string& fragShaderFilePath);
    Shader(Shader&& shader) noexcept;
    Shader& operator=(Shader&& shader) noexcept;

    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) const;
    [[nodiscard]] unsigned int GetID() const;

private:
    unsigned int m_RendererID = 0;
    std::unordered_map<std::string, int> m_UniformLocationCache;

    [[nodiscard]] int GetUniformLocation(const std::string& name);
};