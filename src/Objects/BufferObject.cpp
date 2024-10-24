#include "BufferObject.h"

BufferObject::BufferObject(const BufferObjectType type, const unsigned int count, const GLuint usage)
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

VertexBufferObject::VertexBufferObject(float* vertices, const unsigned int count, const GLuint usage)
: BufferObject(VERTEX_BUFFER_OBJ, count, usage), m_vertices(vertices) {
    glBindBuffer(m_type, m_id);
    glBufferData(m_type, static_cast<GLsizeiptr>(m_count * sizeof(float)), m_vertices, usage);
}

IndexBufferObject::IndexBufferObject(unsigned int* indices, const unsigned int count, const GLuint usage)
: BufferObject(INDEX_BUFFER_OBJ, count, usage), m_indices(indices) {
    glBindBuffer(m_type, m_id);
    glBufferData(m_type, static_cast<GLsizeiptr>(m_count * sizeof(unsigned int)), m_indices, usage);
}
