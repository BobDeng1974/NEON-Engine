#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

#include "Mesh.h"

namespace ContentPipeline
{
	char* LoadShader(char* path);

	Mesh loadOBJ(char* path);
	Mesh loadFBX(char* path);
}