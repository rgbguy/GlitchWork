#pragma once
#include <cstdint>
#include <glad/glad.h>
#include <GLErrorHandler.h>

namespace Gx {

	enum class ShaderType {
		UNDEFINED,
		VERTEX,
		FRAGMENT
	};

	class Shader
	{
	public:
		uint32_t m_ID;
		ShaderType m_type = ShaderType::UNDEFINED;

		uint32_t GetID();
	public:
		Shader(const char* source, ShaderType type);
		~Shader();
	};

}
