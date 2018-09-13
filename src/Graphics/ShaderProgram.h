#pragma once
#define DEBUG

#include <glad/glad.h>

#include "Array"

struct ShaderProgram
{
	private:
		Array shaders;
		uint32_t program;

	public:
		ShaderProgram();
		void addShader(GLenum type, char* source);

		void linkProgram();
};