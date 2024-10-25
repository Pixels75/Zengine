#include "BufferObject.h"

#include <GL/glew.h>

BufferObject::BufferObject(const unsigned int type, const unsigned int count, const unsigned int usage)
    : m_type(type), m_count(count), usage(usage) {
    glGenBuffers(1, &m_id);
}

BufferObject::~BufferObject() {
    glDeleteBuffers(1, &m_id);
}

void BufferObject::Bind() const {
    glBindBuffer(m_type, m_id);
}

void BufferObject::Unbind() const {
    glBindBuffer(m_type, 0);
}

unsigned int BufferObject::GetCount() const {
    return m_count;
}

VertexBufferObject::VertexBufferObject(float *vertices, const unsigned int count, const unsigned int usage)
    : BufferObject(GL_ARRAY_BUFFER, count, usage), m_vertices(vertices) {
    Bind();
    glBufferData(m_type, (GLsizeiptr) (m_count * sizeof(float)), m_vertices, usage);
    Unbind();
}

IndexBufferObject::IndexBufferObject(unsigned int *indices, const unsigned int count, const unsigned int usage)
    : BufferObject(GL_ELEMENT_ARRAY_BUFFER, count, usage), m_indices(indices) {
    Bind();
    glBufferData(m_type, (GLsizeiptr) (m_count * sizeof(unsigned int)), m_indices, usage);
    Unbind();
}
