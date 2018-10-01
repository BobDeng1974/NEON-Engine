#include "Light.h"
#include "string.cpp"

Light::Light(glm::vec3 position, glm::vec3 color, uint32_t type) :
position(position), color(color), type(type)
{

}

void Light::uniform(ShaderProgram program, uint32_t index) {
	uint32_t location = glGetUniformLocation(program.program, "lights[0].position");
	glUniform3fv(location, 1, &position[0]);

	

	location = glGetUniformLocation(program.program, "lights[0].color");
	glUniform3fv(location, 1, &color[0]);
	location = glGetUniformLocation(program.program, "lights[0].type");
	glUniform3fv(location, 1, &type[0]);
}