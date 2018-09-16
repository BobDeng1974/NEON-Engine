#include "Vector3.cpp"
#include <cstdint>

struct Material
{
	Vector3 ambient;
	Vector3 diffuse;
	Vector3 specular;

	void uniform(uint32_t shaderProgram);
};