#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLErrorHandler.h>
#include<glm/glm.hpp>
#include<Shader.h>
#include<Program.h>
#include<Window.h>
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
	Window* window = new Window(800, 800, "GlitchWork");
	
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

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!window->shouldClose())
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		window->update();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	delete window;

	return 0;
}