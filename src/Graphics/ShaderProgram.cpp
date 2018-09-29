#include "ShaderProgram.h"
#include "Debug.h"

ShaderProgram::ShaderProgram()
{
	program = glCreateProgram();
}

void ShaderProgram::addShader(GLenum shaderType, char* source)
{
	uint32_t shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		Debug::Error("Couldn't create shader!");
		Debug::Error(infoLog);
	}

	glAttachShader(program, shader);
}

void ShaderProgram::linkProgram() 
{
	glLinkProgram(program);

	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        //glGetProgramInfoLog([rpgra,], 512, NULL, infoLog);
        Debug::Error("Shader Linking!");
    }
}
void ShaderProgram::useProgram() { glUseProgram(program); }

void ShaderProgram::uniformMatrix4x4(glm::mat4& matrix, uint32_t location) {
	glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}