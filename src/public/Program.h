#pragma once
#include <cstdint>
#include <glad/glad.h>

namespace Gx {
	class Program {
		uint32_t m_ID;

	public:
		uint32_t getID();

		Program();
		Program(uint32_t vertexShaderID, uint32_t fragmentShaderID);
		~Program();

		void AttachShader(uint32_t shaderID);
		void LinkProgram(uint32_t shaderID);
		void DeleteShader(uint32_t shaderID);
		void UseProgram();
	};
}