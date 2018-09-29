#include <glad/glad.h>

#include "Material.h"

Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) : 
ambient(ambient), diffuse(diffuse), specular(specular) {

}

void Material::uniform(uint32_t shaderProgram) {
	uint32_t location = glGetUniformLocation(shaderProgram, "material.ambient");
	glUniform3f(location, ambient.x, ambient.y, ambient.z);

	location = glGetUniformLocation(shaderProgram, "material.diffuse");
	glUniform3f(location, diffuse.x, diffuse.y, diffuse.z);

	location = glGetUniformLocation(shaderProgram, "material.specular");
	glUniform3f(location, specular.x, specular.y, specular.z);
}