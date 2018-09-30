#define LIGHT_POINT 0
#define LIGHT_CONE 1
#define LIGHT_DIRECTIONAL 2

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "ShaderProgram.cpp"

struct Light
{
	glm::vec3 position;
	glm::vec3 color;

	glm::vec3 type;

	Light(glm::vec3 position, glm::vec3 color, uint32_t type);

	void uniform(ShaderProgram program, uint32_t index);
};