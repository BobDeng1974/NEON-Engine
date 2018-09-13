#include "Mesh.h"

Mesh::Mesh(float* vertices, uint32_t* indices, uint32_t verticeCount, uint32_t indiceCount)
{
	this->vertices = vertices;
	this->indices = indices;
	this->verticeCount = verticeCount;
	this->indiceCount = indiceCount;
}