#pragma once
#define DEBUG
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdint>

#include "Array.h"

struct ShaderProgram
{
	private:
		uint32_t program = 0;

	public:
		ShaderProgram();
		void addShader(GLenum type, char* source);

		void linkProgram();
		void useProgram();
};