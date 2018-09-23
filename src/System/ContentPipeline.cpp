#include <iostream>
#include <vector>

#include "ContentPipeline.h"
#include "Debug.h"
#include "File.cpp"

#include "Vector4.cpp"
#include "Vector3.cpp"
#include "Array.h"

// Loads shader on path
// ====================
char* ContentPipeline::LoadShader(char* path)
{
	std::ifstream file(path, std::ios::ate);

	if(!file.is_open())
		Debug::Error("Shader file couldn't be opened!");

	uint32_t size = file.tellg();
	char* shader = new char[size];
	file.seekg(0);

	file.read(shader, size);
	file.close();

	return shader;
}

Mesh ContentPipeline::loadOBJ(char* path)
{
	std::ifstream file(path);
	if(!file.is_open())
		Debug::Error("Couldn't open OBJ file!");
	

	Array<float> vertices(60);
	Array<uint32_t> indices(100);

	Debug::Message("Loop started!");
	string word;
	while(file >> word) {
		if(word == "v") {
			for(uint32_t i = 0; i < 3; i++) {
				file >> word;
				vertices.add(word.toFloat());
			}
		}

		else if(word == "f") {
			for(uint32_t i = 0; i < 3; i++) {
				file >> word;

				uint32_t splitCount = 0;
				string* splits = word.split('/', splitCount);
				indices.add(splits[0].toInt32());
			}
		}
	}

	return Mesh(vertices.array, indices.array, vertices.length, indices.length);
}