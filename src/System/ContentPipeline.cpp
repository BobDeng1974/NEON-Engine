#include "ContentPipeline.h"
#include "Debug.h"

#include <iostream>
#include <vector>
#include <Vector4.cpp>

Mesh ContentPipeline::LoadOBJ(char* path)
{
	std::ifstream file;
	file.open(path);

	if(file.is_open())
		Debug::Error("File couldn't be opened!");

	std::vector<Vector4> vertices;
	std::vector<uint32_t> indices;

	std::string line;
	while(std::getline(file, line))
	{
		uint32_t splitCount = 0;
		std::string* splits = String::Split(line, line.length, ' ', &splitCount);

		// Vertices
		if(strcmp(splits[0], "v"))
			vertices.insert(vertices.begin, Vector4(std::stof(splits[1]), std::stof(splits[2]), std::stof(splits[3])));
		// Faces
		else if(strcmp(splits[1], "f"))
		{
			for(uint32_t i = 1; i <= 3; i++)
			{
				uint32_t count = 0;
				char** faces = String::Split()
			}
		}
	}
}

char* loadShader(char* path)
{
	std::ifstream file;
	file.open(path, std::ios::ate);

	uint32_t size = file.tellg();
	char* shader = new char[size];
	file.seekg(0);

	file.read(shader, size);
	file.close();

	return shader;
}