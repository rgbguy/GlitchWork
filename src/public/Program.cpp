#include "Program.h"

uint32_t Gx::Program::getID()
{
	return m_ID;
}

Gx::Program::Program()
{
	m_ID = glCreateProgram();
}

Gx::Program::~Program()
{
	m_ID = 0;
}

Gx::Program::Program(uint32_t vertexShaderID, uint32_t fragmentShaderID)
{
	m_ID = glCreateProgram();
	AttachShader(vertexShaderID);
	AttachShader(fragmentShaderID);
	LinkProgram(m_ID);
	DeleteShader(vertexShaderID);
	DeleteShader(fragmentShaderID);
}

void Gx::Program::AttachShader(uint32_t shaderID)
{
	glAttachShader(m_ID, shaderID);
}

void Gx::Program::LinkProgram(uint32_t shaderID)
{
	glLinkProgram(m_ID);
}

void Gx::Program::DeleteShader(uint32_t shaderID)
{
	glDeleteShader(shaderID);
}

void Gx::Program::UseProgram()
{
	glUseProgram(m_ID);
}
