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
	char* shader = new char[size + 1];
	file.seekg(0);

	file.read(shader, size);
	file.close();

	shader[size] = '\0';

	return shader;
}

Mesh ContentPipeline::loadOBJ(char* path)
{
	std::ifstream file(path);
	if(!file.is_open())
		Debug::Error("Couldn't open OBJ file!");

	Debug::Message("pepa");
	Array<float> vertices(60);
	Array<float> _normals(60);

	Array<uint32_t> indices(100);
	Array<float> normals(100);

	string word;
	while(file >> word) {
		// Convert vertex definition
		if(!strcmp(word.data(), "v")) {
			for(uint32_t i = 0; i < 3; i++) {
				file >> word;
				vertices.add(std::stof(word.characters));
			}
		}

		if(!strcmp(word.data(), "vn")) {
			for(uint32_t i = 0; i < 3; i++) {
				file >> word;
				_normals.add(std::stof(word.characters));
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

				indices.add(std::stoul(splits[0]->characters) - 1);
				normals.add(_normals[std::stoi(splits[1]->characters) - 1 + i]);
			}
		}
	}
	return Mesh(vertices.array, normals.array, indices.array, vertices.length, normals.length, indices.length);
}