#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ContentPipeline.h"
#include "Debug.h"
#include "File.cpp"
#include "Array.h"
#include "string.h"

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
				std::cout << word;
				vertices.add(std::stof(word.characters));
			}
		}

		// Convert face definition
		else if(!strcmp(word.data(), "f")) {
			// Iterate through face indices
			for(uint32_t i = 0; i < 3; i++) {
				file >> word;

				string** splits;
				uint32_t count = 0;

				word.split('/', splits, count);
				std::cout << "Count : " << count << std::endl;
				for(uint32_t i = 0; i < count; i++) 
					std::cout << splits[i]->characters << "|";

				std::cout << std::endl;
				indices.add(splits[0]->toInt32() - 1);
			}
		}
	}
	std::cout << vertices.length << "|" << indices.length;
	return Mesh(vertices.array, indices.array, vertices.length, indices.length);
}