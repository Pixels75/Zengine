#include "Texture.h"

#include <GL/glew.h>

#include "stb_image.h"

Texture::Texture(const std::string &filepath) : m_filepath(filepath) {
    stbi_set_flip_vertically_on_load(true);
    m_data = stbi_load(filepath.c_str(), &m_width, &m_height, &m_BitsPerPixel, 4);
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(m_data);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(const unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind() const {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
