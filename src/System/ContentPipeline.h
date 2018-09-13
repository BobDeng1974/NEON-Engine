#include <iostream>
#include <fstream>
#include <cstring>

#include "String.h"
#include "Mesh.h"

namespace ContentPipeline
{
	Mesh LoadOBJ(char* path)
	{
		Array<float> vertices(100);
		Array<uint32_t> indices(100);

		std::string line;

		std::ifstream stream(path);
		while(!stream.eof())
		{
			getline(stream, line);
			char** splits = String::Split(line.data(), line.length, ' ', nullptr);

			// Vertices
			if(strcmp(splits[0], "v"))
			{
				for(int i = 1; i <= 3; i++)
					vertices.Add(std::stof(splits[i]));
			}

			else if(strcmp(splits[0], "f"))
			{
				for(int i = 1; i <= 3; i++)
				{
					uint32_t splitCount = 0;
					char** faces = String::Split(splits[i], strlen(splits[i]), '/', &splitCount);
					if(splitCount > 0)
						indices.Add(std::stoi(faces[0]));
				}
			}
		}

		Mesh mesh = Mesh(nullptr, nullptr, 0, 0);
		vertices.copy(mesh.vertices);
		delete &vertices;

		indices.copy(mesh.indices);
		delete &indices;
	}

	char* LoadShader(char* path)
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
}