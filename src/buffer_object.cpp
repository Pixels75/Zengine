#include "buffer_object.h"

BufferObject::BufferObject(const BufferObjectType type, const uint16_t size, const GLuint usage)
: m_type(type), m_size(size) {
    glGenBuffers(1, &m_id);
}

BufferObject::~BufferObject() {
    glDeleteBuffers(1, &m_id);
}

VertexBufferObject::VertexBufferObject(float* vertices, const uint16_t size, const GLuint usage)
: BufferObject(VERTEX_BUFFER_OBJ, size, usage), m_vertices(vertices) {
    glBindBuffer(m_type, m_id);
    glBufferData(m_type, m_size * static_cast<uint16_t>(sizeof(float)), m_vertices, usage);
}

IndexBufferObject::IndexBufferObject(unsigned int* indices, const uint16_t size, const GLuint usage)
: BufferObject(INDEX_BUFFER_OBJ, size, usage), m_indices(indices) {
    glBindBuffer(m_type, m_id);
    glBufferData(m_type, m_size * static_cast<uint16_t>(sizeof(unsigned int)), m_indices, usage);
}
