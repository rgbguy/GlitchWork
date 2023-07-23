#include "VBO.h"

namespace Gx {
    VBO::VBO()
        : m_ID(0), m_dataUsage(GL_STATIC_DRAW), m_dataSize(0) {
        glGenBuffers(1, &m_ID);
    }

    VBO::~VBO() {
        glDeleteBuffers(1, &m_ID);
    }

    void VBO::Bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void VBO::Unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VBO::SetData(const void* data, GLsizei size, GLenum usage) {
        m_dataSize = size;
        m_dataUsage = usage;
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    void VBO::Clear() {
        Bind();
        glBufferData(GL_ARRAY_BUFFER, 0, nullptr, m_dataUsage);
        m_dataSize = 0;
    }

    void VBO::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) {
        Bind();
        glVertexAttribPointer(index, size, type, normalized, stride, offset);
    }

    void VBO::EnableVertexAttribArray(GLuint index) {
        glEnableVertexAttribArray(index);
    }

    void VBO::DisableVertexAttribArray(GLuint index) {
        glDisableVertexAttribArray(index);
    }

    GLsizei VBO::GetDataSize() const {
        return m_dataSize;
    }

    GLenum VBO::GetDataUsage() const {
        return m_dataUsage;
    }
}
