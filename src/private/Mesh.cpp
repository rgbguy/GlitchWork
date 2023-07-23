#include <vector>
#include <glm/glm.hpp>
#include <VBO.h>
#include <Mesh.h>

namespace Gx {
    Mesh::Mesh(const std::vector<glm::vec3>& vertices,
        const std::vector<glm::vec3>& normals,
        const std::vector<glm::vec2>& texCoords) : m_vertexCount(0) {
        m_vao.Bind();

        if (!vertices.empty()) {
            VBO vboVertices;
            vboVertices.SetData(vertices.data(), sizeof(glm::vec3) * vertices.size(), GL_STATIC_DRAW);
            m_vbos.push_back(vboVertices);

            m_vao.AddVertexBuffer(vboVertices, 0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
            m_vertexCount = static_cast<GLsizei>(vertices.size());
        }

        if (!normals.empty()) {
            VBO vboNormals;
            vboNormals.SetData(normals.data(), sizeof(glm::vec3) * normals.size(), GL_STATIC_DRAW);
            m_vbos.push_back(vboNormals);

            m_vao.AddVertexBuffer(vboNormals, 1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        }

        if (!texCoords.empty()) {
            VBO vboTexCoords;
            vboTexCoords.SetData(texCoords.data(), sizeof(glm::vec2) * texCoords.size(), GL_STATIC_DRAW);
            m_vbos.push_back(vboTexCoords);

            m_vao.AddVertexBuffer(vboTexCoords, 2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        }

        m_vao.Unbind();
    }

    Mesh::~Mesh() {
        // VAO and VBOs will be automatically deleted when going out of scope
    }

    void Mesh::Draw() {
        m_vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
        m_vao.Unbind();
    }
}
