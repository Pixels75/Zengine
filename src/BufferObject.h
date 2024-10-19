#pragma once

#include <GL/glew.h>

enum BufferObjectType {
    NULL_BUFFER_OBJ   = 0,
    VERTEX_BUFFER_OBJ = GL_ARRAY_BUFFER,
    INDEX_BUFFER_OBJ  = GL_ELEMENT_ARRAY_BUFFER
};

class BufferObject {
public:
    BufferObject(BufferObjectType type, unsigned int size, GLuint usage);
    ~BufferObject();

    void Bind() const;
    void Unbind() const;
protected:
    BufferObjectType m_type = NULL_BUFFER_OBJ;
    unsigned int m_count = 0;
    GLuint m_id = 0;
};

class VertexBufferObject : public BufferObject {
public:
    VertexBufferObject(float* vertices, unsigned int size, GLuint usage);
private:
    float* m_vertices = nullptr;
};

class IndexBufferObject : public BufferObject {
public:
    IndexBufferObject(unsigned int* indices, unsigned int size, GLuint usage);
private:
    unsigned int* m_indices = nullptr;
};