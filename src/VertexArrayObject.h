#pragma once

#include "BufferObject.h"

enum DataType { NULL_TYPE = 0, INT, FLOAT, UCHAR };

struct VertexArrayLayout {
    VertexArrayLayout(DataType dataType, unsigned int count, unsigned int stride, bool normalize);

    DataType dataType{};
    bool normalize{};
    unsigned int count{};
    unsigned int stride{};
};

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