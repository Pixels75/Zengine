#pragma once

#include <GL/glew.h>

enum BufferObjectType {
    NULL_BUFFER_OBJ   = 0,
    VERTEX_BUFFER_OBJ = GL_ARRAY_BUFFER,
    INDEX_BUFFER_OBJ  = GL_ELEMENT_ARRAY_BUFFER
};

class BufferObject {
public:
    BufferObject(BufferObjectType type, uint16_t size, GLuint usage);
    ~BufferObject();
protected:
    BufferObjectType m_type = NULL_BUFFER_OBJ;
    uint16_t m_size = 0;
    GLuint m_id = 0;
};

class VertexBufferObject : public BufferObject {
public:
    VertexBufferObject(float* vertices, uint16_t size, GLuint usage);
private:
    float* m_vertices = nullptr;
};

class IndexBufferObject : public BufferObject {
public:
    IndexBufferObject(unsigned int* indices, uint16_t size, GLuint usage);
private:
    unsigned int* m_indices = nullptr;
};