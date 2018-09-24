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

	string word;
	while(file >> word) {
		// Convert vertex definition
		if(!strcmp(word.data(), "v")) {
			for(uint32_t i = 0; i < 3; i++) {
				file >> word;
				vertices.add(word.toFloat());
			}
		}

		// Convert face definition
		else if(!strcmp(word.data(), "f")) {
			// Iterate through face indices
			for(uint32_t i = 0; i < 3; i++) {
				file >> word; // Gets first pack of indices
				Debug::Message(word.data());

				uint32_t splitCount = 0; // Stores number of splits
				string** splits = word.split('/', splitCount); // Stores splits
				// Iterate over indices types
				std::cout << splitCount;
				for(int x = 0; x < splitCount; x++) {
					Debug::Message(splits[x]->characters);
				}
				indices.add(splits[0]->toInt32());
			}
		}
	}
	return Mesh(vertices.array, indices.array, vertices.length, indices.length);
}