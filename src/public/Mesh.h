#pragma once
#include <vector>
#include "glm/glm.hpp"
#include "VBO.h"
#include "VAO.h"
#include <glad/glad.h>

namespace Gx {
    class Mesh {
        VAO m_vao;
        std::vector<VBO> m_vbos;
        GLsizei m_vertexCount;

        VBO vboVertices;
        VBO vboNormals;
        VBO vboTexCoords;

    public:
        Mesh(const std::vector<glm::vec3>& vertices,
            const std::vector<glm::vec3>& normals,
            const std::vector<glm::vec2>& texCoords);
        ~Mesh();

        void Draw();
    };
}
