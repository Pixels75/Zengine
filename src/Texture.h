#pragma once

#include <string>

class Texture {
public:
    explicit Texture(const std::string& filepath);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;
private:
    unsigned int m_RendererID = 0;
    int m_width = 0, m_height = 0;
    int m_BitsPerPixel = 0;
    unsigned char* m_data = nullptr;
    std::string m_filepath;
};