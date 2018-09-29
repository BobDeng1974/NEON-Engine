#pragma once
#include <cstdint>

struct Mesh
{
	public:
		float* vertices;
		float* normals;

		uint32_t* indices;

		uint32_t verticeCount;
		uint32_t normalCount;
		uint32_t indiceCount;

		Mesh(float* vertices, float* normals, uint32_t* indices, uint32_t verticeCount, uint32_t normalCount, uint32_t indiceCount);
};