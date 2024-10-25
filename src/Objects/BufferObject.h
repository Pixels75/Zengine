#pragma once

class BufferObject {
public:
    BufferObject(unsigned int type, unsigned int count, unsigned int usage);

    ~BufferObject();

    void Bind() const;

    void Unbind() const;

    [[nodiscard]] unsigned int GetCount() const;

protected:
    unsigned int m_type = 0;
    unsigned int m_count = 0;
    unsigned int usage;
    unsigned int m_id = 0;
};

class VertexBufferObject : public BufferObject {
public:
    VertexBufferObject(float *vertices, unsigned int count, unsigned int usage);

private:
    float *m_vertices = nullptr;
};

class IndexBufferObject : public BufferObject {
public:
    IndexBufferObject(unsigned int *indices, unsigned int count, unsigned int usage);

private:
    unsigned int *m_indices = nullptr;
};
