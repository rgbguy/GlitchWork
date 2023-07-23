#pragma once
#include <cstdint>
#include <glad/glad.h>
#include "VBO.h"

namespace Gx {
    class VAO {
        uint32_t m_ID;
    public:
        VAO();
        ~VAO();

        void Bind();
        void Unbind();

        void AddVertexBuffer(VBO& vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset);
        void EnableAttribute(GLuint index);
        void DisableAttribute(GLuint index);
    };
}
