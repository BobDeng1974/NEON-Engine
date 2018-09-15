#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

#include "String.h"
#include "Mesh.h"

namespace ContentPipeline
{
	Mesh LoadOBJ(char* path);

	char* LoadShader(char* path);
}