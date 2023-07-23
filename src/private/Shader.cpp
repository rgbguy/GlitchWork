#include "Shader.h"

uint32_t Gx::Shader::GetID()
{
	return m_ID;
}

Gx::Shader::Shader(const char* source, ShaderType type)
{
	switch (type)
	{
		case Gx::ShaderType::VERTEX:
			m_ID = glCreateShader(GL_VERTEX_SHADER);
			break;

		case Gx::ShaderType::FRAGMENT:
			m_ID = glCreateShader(GL_FRAGMENT_SHADER);
			break;

		default:
			break;
	}

	glShaderSource(m_ID, 1, &source, NULL);
	GLCall(glCompileShader(m_ID));
	CheckShaderStatus(m_ID);
}

Gx::Shader::~Shader()
{
	m_ID = 0;
	m_type = ShaderType::UNDEFINED;
}
