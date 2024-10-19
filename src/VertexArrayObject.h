#pragma once

#include "BufferObject.h"

class VertexArrayObject {
public:
    VertexArrayObject();
    ~VertexArrayObject();

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(const VertexBufferObject& vertexBuffer) const;
private:
    unsigned int m_id;
};