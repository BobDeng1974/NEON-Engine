#pragma once
#include <cstdint>

struct Mesh
{
	public:
		float* vertices;
		uint32_t* indices;

		uint32_t verticeCount;
		uint32_t indiceCount;

		Mesh(float* vertices, uint32_t * indices, uint32_t verticeCount, uint32_t indiceCount);
};