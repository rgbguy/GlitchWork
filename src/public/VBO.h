#pragma once
#include <cstdint>
#include <glad/glad.h>

namespace Gx {
    class VBO {
        uint32_t m_ID;
        GLenum m_dataUsage;
        GLsizei m_dataSize;
    public:
        VBO();
        ~VBO();

        void Bind();
        void Unbind();

        void SetData(const void* data, GLsizei size, GLenum usage);
        void Clear();

        void VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset);
        void EnableVertexAttribArray(GLuint index);
        void DisableVertexAttribArray(GLuint index);

        GLsizei GetDataSize() const;
        GLenum GetDataUsage() const;
    };
}
