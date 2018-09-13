#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	program = glCreateProgram();
}

void ShaderProgram::addShader(GLenum shaderType, char* source)
{
	uint32_t shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	glAttachShader(program, shader);
}

void ShaderProgram::linkProgram() { glLinkProgram(program); }