#include "VertexArrayObject.h"

#include <GL/glew.h>

VertexArrayObject::VertexArrayObject()
    : m_id(0) {
    glGenVertexArrays(1, &m_id);
    glBindVertexArray(m_id);
}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &m_id);
}

void VertexArrayObject::Bind() const {
    glBindVertexArray(m_id);
}

void VertexArrayObject::Unbind() const {
    glBindVertexArray(0);
}

void VertexArrayObject::AddVertexBuffer(const VertexBufferObject &vertexBuffer,
                                        const VertexBufferLayout &layout) const {
    vertexBuffer.Bind();
    unsigned int offset = 0;
    for (int i = 0; i < layout.elements.size(); i++) {
        const unsigned int size = layout.elements[i].GetSize();

        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
            i,
            (GLint) layout.elements[i].count,
            layout.elements[i].type,
            layout.elements[i].normalized,
            (GLint) layout.stride,
            (const void *) offset
        );
        offset += layout.elements[i].count * size;
    }
}
