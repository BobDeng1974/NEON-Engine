#pragma once
#define DEBUG

#include <glad/glad.h>

#include "Array.h"

struct ShaderProgram
{
	private:
		Array<uint32_t> shaders;
		uint32_t program;

	public:
		ShaderProgram();
		void addShader(GLenum type, char* source);

		void linkProgram();
};