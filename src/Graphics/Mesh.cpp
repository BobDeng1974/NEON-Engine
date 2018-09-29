#include "Mesh.h"

Mesh::Mesh(float* vertices, float* normals, uint32_t* indices, uint32_t verticeCount, uint32_t normalCount, uint32_t indiceCount) :
vertices(vertices), normals(normals), indices(indices), verticeCount(verticeCount), normalCount(normalCount), indiceCount(indiceCount)
{
	
}