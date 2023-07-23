#include "VAO.h"

namespace Gx {
    VAO::VAO() : m_ID(0) {
        glGenVertexArrays(1, &m_ID);
    }

    VAO::~VAO() {
        glDeleteVertexArrays(1, &m_ID);
    }

    void VAO::Bind() {
        glBindVertexArray(m_ID);
    }

    void VAO::Unbind() {
        glBindVertexArray(0);
    }

    void VAO::AddVertexBuffer(VBO& vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) {
        Bind();
        vbo.Bind();
        glVertexAttribPointer(index, size, type, normalized, stride, offset);
        EnableAttribute(index);
        vbo.Unbind();
    }

    void VAO::EnableAttribute(GLuint index) {
        glEnableVertexAttribArray(index);
    }

    void VAO::DisableAttribute(GLuint index) {
        glDisableVertexAttribArray(index);
    }
}
