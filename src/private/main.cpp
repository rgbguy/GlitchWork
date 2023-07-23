#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLErrorHandler.h>
#include<glm/glm.hpp>
#include<Shader.h>
#include<Program.h>
#include<Window.h>
#include<VBO.h>
#include<vector>
#include<Mesh.h>
#include<memory> // Include for smart pointers

const char* vertexShaderSource = R"(
#version 460 core
layout (location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 460 core
out vec4 FragColor;
void main()
{
    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
)";


int main()
{
    // Use unique_ptr for Window and Mesh to manage memory
    std::unique_ptr<Gx::Window> window = std::make_unique<Gx::Window>(800, 800, "GlitchWork");

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    uint32_t vsID = Gx::Shader(vertexShaderSource, Gx::ShaderType::VERTEX).GetID();
    uint32_t fsID = Gx::Shader(fragmentShaderSource, Gx::ShaderType::FRAGMENT).GetID();
    uint32_t shaderProgram = Gx::Program(vsID, fsID).getID();

    GLfloat vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Create a mesh from the vertex data
    std::vector<glm::vec3> meshVertices;
    for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
        meshVertices.push_back(glm::vec3(vertices[i], vertices[i + 1], vertices[i + 2]));
    }

    // Use unique_ptr for Mesh to manage memory
    std::unique_ptr<Gx::Mesh> mesh = std::make_unique<Gx::Mesh>(meshVertices, std::vector<glm::vec3>(), std::vector<glm::vec2>());

    while (!window->shouldClose())
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);

        mesh->Draw();

        window->update();
    }

    glDeleteProgram(shaderProgram);

    return 0;
}
