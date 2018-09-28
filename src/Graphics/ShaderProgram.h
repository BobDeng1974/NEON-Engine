#pragma once
#define DEBUG
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdint>

#include "Array.h"
#include "string.cpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ShaderProgram
{
	private:

	public:
		uint32_t program = 0;

		ShaderProgram();
		ShaderProgram(string vertexShader, string fragmentShader);
		void addShader(GLenum type, char* source);

		void linkProgram();
		void useProgram();

		// Uniforms
		// ========
		void uniformMatrix4x4(glm::mat4& matrix, uint32_t location);
};