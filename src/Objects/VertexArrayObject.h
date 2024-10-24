#pragma once

#include "BufferObject.h"
#include "VertexBufferLayout.h"

class VertexArrayObject {
public:
    VertexArrayObject();
    ~VertexArrayObject();

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(const VertexBufferObject& vertexBuffer, const VertexBufferLayout& layout) const;
private:
    unsigned int m_id;
};