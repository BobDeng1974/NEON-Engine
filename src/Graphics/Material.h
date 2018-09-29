#pragma once

#include <glm/glm.hpp>
#include <cstdint>

struct Material
{
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	void uniform(uint32_t shaderProgram);
};