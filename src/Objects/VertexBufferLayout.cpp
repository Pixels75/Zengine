#include "VertexBufferLayout.h"

#include <GL/glew.h>

unsigned int VertexBufferElement::GetStride() const {
    return count * GetSize();
}

unsigned int VertexBufferElement::GetSize() const {
    switch (type) {
        case GL_FLOAT:          return  4;
        case GL_INT:            return  4;
        case GL_UNSIGNED_INT:   return  4;
        case GL_SHORT:          return  2;
        case GL_UNSIGNED_SHORT: return  2;
        case GL_BOOL:           return  1;
        case GL_BYTE:           return  2;
        case GL_UNSIGNED_BYTE:  return  4;
        default:                return -1;
    }
}
