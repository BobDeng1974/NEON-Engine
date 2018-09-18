#include <iostream>
#include <vector>

#include "ContentPipeline.h"
#include "Debug.h"
#include "File.cpp"

#include "Vector4.cpp"


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
	
	while(!file.eof())
	{
		string word = File::readWord(file);
		if(word == "v")
		{
			
		}
	}
}