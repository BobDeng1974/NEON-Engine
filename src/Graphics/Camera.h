#include <glm/glm.hpp>

#include "ShaderProgram.cpp"

struct Camera
{
	glm::vec3 position;

	Camera();
	Camera(glm::vec3 initialiPosition);

	void move(glm::vec3 move);
	void rotate(glm::vec3 rotation);

	void uniform(ShaderProgram program);
};