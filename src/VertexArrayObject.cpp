#include "VertexArrayObject.h"

#include <GL/glew.h>

VertexArrayLayout::VertexArrayLayout(const DataType dataType, const unsigned int count, const unsigned int stride, const bool normalize)
: dataType(dataType), normalize(normalize), count(count), stride(stride){}

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

void VertexArrayObject::AddVertexBuffer(const VertexBufferObject& vertexBuffer) const {
    vertexBuffer.Bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
}
