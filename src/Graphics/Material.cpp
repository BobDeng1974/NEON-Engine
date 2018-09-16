#include <glad/glad.h>

#include "Material.h"

void Material::uniform(uint32_t shaderProgram) {
	uint32_t location = glGetUniformLocation(shaderProgram, "ambient");
	glUniform3f(location, ambient.x, ambient.y, ambient.z);

	uint32_t location = glGetUniformLocation(shaderProgram, "diffuse");
	glUniform3f(location, diffuse.x, diffuse.y, diffuse.z);

	uint32_t location = glGetUniformLocation(shaderProgram, "specular");
	glUniform3f(location, specular.x, specular.y, specular.z);
}