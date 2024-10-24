#pragma once

#include <stdexcept>
#include <vector>

#include <GL/glew.h>

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    bool normalized;

    [[nodiscard]] unsigned int GetSize()   const;
    [[nodiscard]] unsigned int GetStride() const;
};

class VertexBufferLayout {
public:
    std::vector<VertexBufferElement> elements;
    unsigned int stride = 0;

    template<typename T>
    void Push(unsigned int count) {
        throw std::invalid_argument("Invalid type");
    }

    template<>
    void Push<float>(const unsigned int count) {
        if (count < 1 || count > 4)
            throw std::invalid_argument("Invalid count");
        elements.push_back({GL_FLOAT, count, GL_FALSE});
        stride += sizeof(GLfloat) * count;
    }

    template<>
    void Push<unsigned int>(const unsigned int count) {
        if (count < 1 || count > 4)
            throw std::invalid_argument("Invalid count");
        elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        stride += sizeof(GLuint) * count;
    }

    template<>
    void Push<unsigned char>(const unsigned int count) {
        if (count < 1 || count > 4)
            throw std::invalid_argument("Invalid count");
        elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
        stride += sizeof(GLubyte) * count;
    }
};